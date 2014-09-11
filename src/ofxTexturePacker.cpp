// ------------------------------------------------------------------
// ofxTexturePacker.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------
#include "ofxTexturePacker.h"

ofxTexturePacker::ofxTexturePacker() : texture(NULL), loader(NULL) {
   
}

ofxTexturePacker::~ofxTexturePacker() {
    
    removeTexture();
    removeLoader();
    
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

void ofxTexturePacker::removeLoader() {
    if(loader) {
        delete loader;
        loader = NULL;
    }
}

void ofxTexturePacker::createLoader() {
    if(loader) {
        removeLoader();
    }
    loader = new ofxTPLoader();
    
}

void ofxTexturePacker::removeTexture() {
    if(texture) {
        delete texture;
        texture = NULL;
    }
}

bool ofxTexturePacker::load(const string& fileToLoad, bool bLoadTexture) {
    
    removeLoader();
    removeTexture();
    
    //----------- Load sprites
    createLoader();
    vector<ofxTPSpriteData*> spriteData = loader->load(fileToLoad);
    
    //----------- Load Texture
    if(loader->getImagePath() != "") {
        if(bLoadTexture == true) {
            texture = new ofTexture();
            if(ofLoadImage(*texture, loader->getImagePath())) {
                ofLog(OF_LOG_VERBOSE, "ofxTexturePacker::loaded image");
            } else {
                ofLog(OF_LOG_ERROR, "ofxTexturePacker:: failed to load texture: " + loader->getImagePath());
                removeTexture();
                return false;
            }
        }
    }
    //----------- Create Sprites
    if(spriteData.size() != 0) {
        for(unsigned int i=0; i<=spriteData.size()-1; i++) {
            ofxTPSprite *sprite = new ofxTPSprite(spriteData[i]);
            if(texture != NULL) {
                sprite->setTexture(texture);
            }
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

void ofxTexturePacker::setTexture(ofTexture* newTexture) {
    if(newTexture == NULL) {
       ofLog(OF_LOG_ERROR, "ofxTexturePacker::setTexture, passed texture* is NULL");
        return;
    }
    if(texture) {
        delete texture;
        texture = NULL;
    }
    
    texture = newTexture;
    
    if(sprites.size() != 0) {
        unsigned int spriteSize = sprites.size()-1;
        for(unsigned int i=0; i<=spriteSize; i++) {
            ofxTPSprite* sprite = sprites[i];
            if(sprite != NULL) {
                sprite->setTexture(texture);
            }
        }
    }
    
    // -------------- Update sprites with the texture
    if(animatedSprites.size() != 0) {
        unsigned int spriteSize = animatedSprites.size()-1;
        for(unsigned int i=0; i<=spriteSize; i++) {
            ofxTPAnimatedSprite* animatedSprite = animatedSprites[i];
            if(animatedSprite != NULL) {
                animatedSprite->setTexture(texture);
            }
        }
    }

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