// ------------------------------------------------------------------
// ofxTPSprite.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------
#pragma once
#include "ofMain.h"
#include "ofxTPSpriteCore.h"
#include "ofxTPSpriteData.h"

//------------------------------------------------------
class ofxTPSprite : public ofxTPSpriteCore {
public:
    ofxTPSprite(ofxTPSpriteData* theData);
    
    void draw(int x, int y);
    
    const string& getName() const;
    ofxTPSpriteData* getData();
protected:
    ofxTPSpriteData* data;
};
//----------
inline const string& ofxTPSprite::getName() const {
    return data->getName();
}
//----------
inline ofxTPSpriteData* ofxTPSprite::getData() {
    return data;
}
