// ------------------------------------------------------------------
// ofxTexturePacker.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------
#include "ofxTexturePacker.h"

ofxTexturePacker::ofxTexturePacker() {
    texture = NULL;
}

ofxTexturePacker::~ofxTexturePacker() {
    if(texture) {
        delete texture;
        texture = NULL;
    }
    if(animatedSprites.size() != 0) {
        int animatedSpritesSize = animatedSprites.size()-1;
        for(int i=animatedSpritesSize; i>=0; i--) {
            ofxTPAnimatedSprite* sprite = animatedSprites[i];
            if(sprite != NULL) {
                delete sprite;
                sprite = NULL;
            }
        }
    }
    if(sprites.size() != 0) {
        int spriteSize = sprites.size()-1;
        for(int i=spriteSize; i>=0; i--) {
            ofxTPSprite* sprite = sprites[i];
            if(sprite != NULL) {
                delete sprite;
                sprite = NULL;
            }
        }
    }
}

vector<string> ofxTexturePacker::getAnimationNames(){
    vector<string> names;
    int spriteSize = sprites.size()-1;
    for(unsigned int i=0; i<=spriteSize; i++) {
        ofxTPSprite* sprite = sprites[i];
        if(sprite->getData()->getAnimated()){
            ofLog(OF_LOG_VERBOSE)<<sprite->getData()->getAnimationName()<<endl;
            names.push_back(sprite->getData()->getAnimationName());
        }
    }
    return names;
}

vector<string> ofxTexturePacker::getSpriteNames(){
    vector<string> names;
    int spriteSize = sprites.size()-1;
    for(unsigned int i=0; i<=spriteSize; i++) {
        ofxTPSprite* sprite = sprites[i];
        names.push_back(sprite->getName());
    }
    return names;
}

bool ofxTexturePacker::load(const string& fileToLoad) {
    //----------- Load sprites
    vector<ofxTPSpriteData*> spriteData = loader.load(fileToLoad);
    texture = new ofTexture();
    //----------- Load Texture
    if(loader.getImagePath() != "") {
        if(ofLoadImage(*texture, loader.getImagePath())) {
            ofLog(OF_LOG_VERBOSE, "ofxTexturePacker::loaded image");
        } else {
            ofLog(OF_LOG_ERROR, "ofxTexturePacker::image not loaded");
            delete texture;
            texture = NULL;
            return false;
        }
    }
    //----------- Create Sprites
    if(spriteData.size() != 0) {
        for(unsigned int i=0; i<=spriteData.size()-1; i++) {
            ofxTPSprite *sprite = new ofxTPSprite(spriteData[i]);
            sprite->setTexture(texture);
            sprites.push_back(sprite);
            if(spriteData[i]->getAnimated()) {
                ofxTPAnimatedSprite* sp = getAnimatedSprite(spriteData[i]->getAnimationName());
                if(sp == NULL) {
                    sp = new ofxTPAnimatedSprite();
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
        int spriteSize = sprites.size()-1;
        for(int i=0; i<=spriteSize; i++) {
            ofxTPSprite* sprite = sprites[i];
            if(sprite != NULL) {
                sprite->draw(ofGetWidth()/2-i*55*sin(ofGetElapsedTimef()),0);
            }
        }
    }
}

ofxTPSprite* ofxTexturePacker::getSprite(const string& spriteName) {
    if(sprites.size() != 0) {
        unsigned int spriteSize = sprites.size()-1;
        for(unsigned int i=0; i<=spriteSize; i++) {
            ofxTPSprite* sprite = sprites[i];
            if(sprite != NULL) {
                if(sprite->compareName(spriteName)) {
                    return sprite;
                }
            }
        }
    } else {
        return NULL;
    }
    return NULL;
}

ofxTPAnimatedSprite* ofxTexturePacker::getAnimatedSprite(const string& spriteName) {
    if(animatedSprites.size() != 0) {
        unsigned int spriteSize = animatedSprites.size()-1;
        for(unsigned int i=0; i<=spriteSize; i++) {
            ofxTPAnimatedSprite* animatedSprite = animatedSprites[i];
            if(animatedSprite != NULL) {
                if(animatedSprite->compareName(spriteName)) {
                    return animatedSprite;
                }
            }
        }
    } else {
        return NULL;
    }
    return NULL;
}