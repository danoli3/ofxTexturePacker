// ------------------------------------------------------------------
// ofxTPSpriteCore.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#pragma once

#ifndef __ofxTPSpriteCore__
#define __ofxTPSpriteCore__

#include "ofMain.h"
#include "ofxTPTypes.h"


class ofxTPSpriteCore {
public:
    
    virtual void draw(int x, int y) {}
    virtual void update(int x, int y) {}
    
    ofxTPSpriteType getType() {
        return type;
    }
    ofxTPSpriteType type;
    
    void setTexture(ofTexture* tex) {
        texture = tex;
    }
    
    virtual void setName(const string& name) {
        //
    }
    
    virtual string getName() const {
        return "";
    }
    
    bool compareName(const string & otherName) const {
        return (getName() == otherName);
    }
    
protected:
    ofTexture * texture;
};

#endif /* defined(__ofxTPSpriteCore__) */
