// ------------------------------------------------------------------
// ofxTexturePacker.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------
#include "ofxTexturePacker.h"

ofxTexturePacker::ofxTexturePacker() :
    texture(),
    loader(),
    bDebugMode(false)
{
}

ofxTexturePacker::~ofxTexturePacker() {
    
    removeTexture();
    removeLoader();
    
    animatedSprites.clear();
    sprites.clear();
}

void ofxTexturePacker::removeLoader() {
    loader.reset();
}

void ofxTexturePacker::createLoader() {
    loader = ofxTPLoaderPtr(new ofxTPLoader());
}

void ofxTexturePacker::removeTexture() {
    texture.reset();
}

vector<string> ofxTexturePacker::getAnimationNames(){
    vector<string> names;
    for(unsigned int i=0; i < sprites.size(); i++) {
        ofxTPSpritePtr sprite = sprites[i];
        if(sprite->getData()->isAnimated()){
            if(find(names.begin(), names.end(), sprite->getData()->getAnimationName()) == names.end()){
                names.push_back(sprite->getData()->getAnimationName());
                ofLog(OF_LOG_VERBOSE)<<"Animation Named "<<names.back()<<" found"<<endl;
            }
        }
    }
    return names;
}

vector<string> ofxTexturePacker::getSpriteNames(){
    vector<string> names;
    for(unsigned int i=0; i < sprites.size(); i++) {
        ofxTPSpritePtr sprite = sprites[i];
        names.push_back(sprite->getName());
        ofLog(OF_LOG_VERBOSE)<<"Sprite Named "<<names.back()<<" found"<<endl;
    }
    return names;
}


bool ofxTexturePacker::load(const string& fileToLoad, bool bLoadTexture) {
    
    removeLoader();
    removeTexture();
    
    //----------- Load sprites
    createLoader();
    vector<ofxTPSpriteDataPtr> spriteData = loader->load(fileToLoad);
    
    //----------- Load Texture
    if(!loader->getImagePath().empty()) {
        if(bLoadTexture) {
            texture = shared_ptr<ofTexture>(new ofTexture());
            
            string textureLocation;
            
            string directory = ofFilePath::getEnclosingDirectory(fileToLoad, false);
            bool isTextureWithXML = ofFile::doesFileExist((directory + loader->getImagePath()));
            if(isTextureWithXML) {
                textureLocation = directory + loader->getImagePath();
            } else {
                textureLocation = loader->getImagePath();
            }
            
            if(ofLoadImage(*texture, textureLocation)) {
                ofLog(OF_LOG_VERBOSE, "Texture '%s' loaded", textureLocation.c_str());
            } else {
                ofLog(OF_LOG_ERROR, "Failed to load texture '%s'", textureLocation.c_str());
                removeTexture();
                return false;
            }
        }
    }
    //----------- Create Sprites
    if(spriteData.size() != 0) {
        for(unsigned int i=0; i < spriteData.size(); i++) {
            ofxTPSpritePtr sprite = ofxTPSpritePtr(new ofxTPSprite(spriteData[i]));
            if(texture) {
                sprite->setTexture(texture);
            }
            sprites.push_back(sprite);
            if(spriteData[i]->isAnimated()) {
                ofxTPAnimatedSpritePtr sp = getAnimatedSprite(spriteData[i]->getAnimationName());
                if(!sp) {
                    sp = ofxTPAnimatedSpritePtr(new ofxTPAnimatedSprite());
                    sp->setName(spriteData[i]->getAnimationName());
                    animatedSprites.push_back(sp);
                }
                sp->addSprite(sprite);
            }
        }
        return true;
    } else {
        ofLog(OF_LOG_ERROR, "ofxTexturePacker::sprites empty");
        return false;
    }
}

void ofxTexturePacker::drawTest() {
    ofSetColor(255);
    if(texture) {
        texture->draw(0,0);
    }
    ofSetColor(255,0,0);
    if(sprites.size() != 0) {
        for(int i=0; i < sprites.size(); i++) {
            ofxTPSpritePtr sprite = sprites[i];
            if (sprite != NULL) {
                sprite->draw(ofGetWidth()/2-i*55*sin(ofGetElapsedTimef()),0);
            }
        }
    }
}

ofxTPSpritePtr ofxTexturePacker::getSprite(const string& spriteName) {
    if(sprites.size() != 0) {
        for(unsigned int i=0; i < sprites.size(); i++) {
            ofxTPSpritePtr sprite = sprites[i];
            if (sprite && sprite->compareName(spriteName)) {
                return sprite;
            }
        }
    } else {
        return ofxTPSpritePtr();
    }
    return ofxTPSpritePtr();
}

void ofxTexturePacker::setTexture(shared_ptr<ofTexture> newTexture) {
    if(!newTexture) {
       ofLog(OF_LOG_ERROR, "ofxTexturePacker::setTexture, passed texture* is NULL");
        return;
    }
    texture = newTexture;
    
    if(!sprites.empty()) {
        for(unsigned int i=0; i < sprites.size(); i++) {
            ofxTPSpritePtr sprite = sprites[i];
            if(sprite) {
                sprite->setTexture(texture);
            }
        }
    }
    
    // -------------- Update sprites with the texture
    if(!animatedSprites.empty()) {
        for(unsigned int i=0; i < animatedSprites.size(); i++) {
            ofxTPAnimatedSpritePtr animatedSprite = animatedSprites[i];
            if(animatedSprite) {
                animatedSprite->setTexture(texture);
            }
        }
    }

}

ofxTPAnimatedSpritePtr ofxTexturePacker::getAnimatedSprite(const string& spriteName) {
    if(!animatedSprites.empty()) {
        for(unsigned int i=0; i < animatedSprites.size(); i++) {
            ofxTPAnimatedSpritePtr animatedSprite = animatedSprites[i];
            if(animatedSprite && animatedSprite->compareName(spriteName)) {
                return animatedSprite;
            }
        }
    } else {
        return ofxTPAnimatedSpritePtr();
    }
    return ofxTPAnimatedSpritePtr();
}

void ofxTexturePacker::setDebugMode(bool debugMode) {
    if(debugMode != bDebugMode) {
        bDebugMode = debugMode;
        if(sprites.size() != 0) {
            for(unsigned int i=0; i < sprites.size(); i++) {
                ofxTPSpritePtr sprite = sprites[i];
                if(sprite) {
                    sprite->setDebugMode(bDebugMode);
                }
            }
        }
        if(animatedSprites.size() != 0) {
            for(unsigned int i=0; i < animatedSprites.size(); i++) {
                ofxTPAnimatedSpritePtr animatedSprite = animatedSprites[i];
                if(animatedSprite) {
                    animatedSprite->setDebugMode(bDebugMode);
                }
            }
        }
    } else {
        // already set
        return;
    }
}
