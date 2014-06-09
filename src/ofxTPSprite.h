// ------------------------------------------------------------------
// ofxTPSprite.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------
#pragma once

#ifndef __ofxTPSprite__
#define __ofxTPSprite__

#include "ofMain.h"
#include "ofxTPSpriteCore.h"
#include "ofxTPSpriteData.h"

class ofxTPSprite : public ofxTPSpriteCore {
public:
    ofxTPSprite(ofxTPSpriteData* theData);
    void draw(int x, int y);
    string getName() const;
    
    ofxTPSpriteData* data;
protected:
    
};

inline string ofxTPSprite::getName() const {
    return data->getName();
}

#endif /* defined(__ofxTPSprite__) */
