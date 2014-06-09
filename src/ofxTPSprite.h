// ------------------------------------------------------------------
// ofxTPSprite.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#ifndef __ofxTPSprite__
#define __ofxTPSprite__

#include "ofMain.h"
#include "ofxTPSpriteCore.h"
#include "ofxTPSpriteData.h"

class ofxTPSprite : public ofxTPSpriteCore {
public:
    ofxTPSprite(ofxTPSpriteData* theData) {
        data = theData;
    }
    
    void draw(int x, int y) {
        if(data->getRotated()) {
            ofPushMatrix();
            ofRotate(90);
        }
        texture->drawSubsection(x, y, data->w, data->h, data->x, data->y);
        if(data->getRotated()) {
            ofPopMatrix();
        }
    }
    
    void update(int x, int y) {
        
    }
    
    virtual string getName() const {
        return data->getName();
    }
    
    
protected:
    ofxTPSpriteData* data;
};


#endif /* defined(__ofxTPSprite__) */
