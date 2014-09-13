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
    if(data->isRotated()) {
        ofPushMatrix();
        ofTranslate(0, data->getWidth());
        ofRotate(-90);
    }
    if(data->isDebugMode()){
        ofRect(x, y, data->getWidth(), data->getHeight());
    }
    texture->drawSubsection(x+data->getOffsetX(), y+data->getOffsetY(), data->getW(), data->getH(), data->getX(), data->getY(), data->getW(), data->getH());
    
    if(data->isRotated()) {
        ofPopMatrix();
    }
}