// ------------------------------------------------------------------
// ofxTPSprite.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------
#include "ofxTPSprite.h"

ofxTPSprite::ofxTPSprite(ofxTPSpriteData* theData) {
    data = theData;
}
float ofxTPSprite::getWidth(){
    return data->getW();
}

void ofxTPSprite::draw(int x, int y) {
    if(data->getRotated()) {
        ofPushMatrix();
        ofRotate(-90);
        ofTranslate(-(data->getOffsetWidth()), 0);
    }
    texture->drawSubsection(x, y, data->getW(), data->getH(), data->getX(), data->getY(), data->getW(), data->getH());
    if(data->getRotated()) {
        ofPopMatrix();
    }
}