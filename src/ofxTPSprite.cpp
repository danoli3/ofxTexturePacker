// ------------------------------------------------------------------
// ofxTPSprite.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------
#include "ofxTPSprite.h"

ofxTPSprite::ofxTPSprite(ofxTPSpriteData* theData) {
    data = theData;
}

void ofxTPSprite::draw(int x, int y) {
    if(data->getRotated()) {
        ofPushMatrix();
        ofRotate(90);
    }
    texture->drawSubsection(x+data->getOffsetX(), y+data->getOffsetY(),
                            data->getW(), data->getH(), data->getX(), data->getY());
    if(data->getRotated()) {
        ofPopMatrix();
    }
}