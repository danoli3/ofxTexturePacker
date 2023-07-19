// ------------------------------------------------------------------
// ofxTPSpriteData.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#include "ofxTPSpriteData.h"

ofxTPSpriteData::ofxTPSpriteData() : name(""), animationName(""),
                                    x(0), y(0), w(0), h(0), pX(0), pY(0), oX(0), oY(0), oW(0), oH(0),
                                    frame(0), bAnimated(false), bTrimmed(false), bPivot(false), bDebugMode(false) {
    
}

void ofxTPSpriteData::setup() {
    
    if(oX != 0 || oY != 0) {
        bTrimmed = true;
    }
    
    if(pX != 0 || pY != 0) {
        bPivot = true;
    }
    
}


void ofxTPSpriteData::determineAnimated() {
   
//---------- CP-11 version
    smatch subStrings;
    regex expression ("((?:(?![\\d]*[.].*$)[\\w\\s])+)([\\d]*)([.].*)$");
    
    if (regex_match(name, subStrings, expression)) {
        if (subStrings.length(2) > 0) {
            if (subStrings.length(1) > 0) {
                animationName = subStrings[1];
            }
            bAnimated = true;
            frame = ofToInt(subStrings[2]);
        } else {
            bAnimated = false;
        }
    } else {
        ofLog(OF_LOG_ERROR, "ERROR: Filename format not recognised for " + name);
    }
}

void ofxTPSpriteData::extractFrame() {
    
}
