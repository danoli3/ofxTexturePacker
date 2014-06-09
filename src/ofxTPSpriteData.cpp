// ------------------------------------------------------------------
// ofxTPSpriteData.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#include "ofxTPSpriteData.h"


ofxTPSpriteData::ofxTPSpriteData() : name(""), animationName(""), x(0), y(0), w(0), h(0), oX(0), oY(0), oW(0), oH(0), frame(0), isAnimated(false) {
    
}


void ofxTPSpriteData::determineAnimated() {
    smatch subStrings;
    regex expression ("((?:(?![\\d]*[.].*$)[\\w\\s])+)([\\d]*)([.].*)$");
    
    if (regex_match(name, subStrings, expression)) {
        if (subStrings.length(2) > 0) {
            if (subStrings.length(1) > 0) {
                animationName = subStrings[1];
            }
            isAnimated = true;
            frame = ofToInt(subStrings[2]);
        } else {
            isAnimated = false;
        }
    } else {
        ofLog(OF_LOG_ERROR, "ERROR: Filename format not recognised for " + name);
    }
}

void ofxTPSpriteData::extractFrame() {
    
}