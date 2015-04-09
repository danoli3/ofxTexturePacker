// ------------------------------------------------------------------
// ofxTPSprite.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------
#pragma once
#include "ofMain.h"
#include "ofxTPSpriteCore.h"
#include "ofxTPSpriteData.h"

class ofxTPSprite;
typedef shared_ptr<ofxTPSprite> ofxTPSpritePtr;

//------------------------------------------------------
class ofxTPSprite : public ofxTPSpriteCore {
public:
    ofxTPSprite(ofxTPSpriteDataPtr data);
    
    void draw(int x, int y);
    
    const string& getName() const;
    ofxTPSpriteDataPtr getData();
    float getWidth();
    void setDebugMode(bool debugMode);
protected:
    ofxTPSpriteDataPtr data;
};
//----------
inline const string& ofxTPSprite::getName() const {
    return data->getName();
}
//----------
inline ofxTPSpriteDataPtr ofxTPSprite::getData() {
    return data;
}

inline void ofxTPSprite::setDebugMode(const bool debugMode) {
    if (data)
        data->setDebugMode(debugMode);
}
