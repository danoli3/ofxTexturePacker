// ------------------------------------------------------------------
// ofxTPSpriteData.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#pragma once

#ifndef __ofxTPSpriteData__
#define __ofxTPSpriteData__

#include "ofMain.h"
#include "ofxTPSpriteCore.h"

#include <iostream>
#include <string>

//#include "regex.h"  // posix
#include <Poco/RegularExpression.h>

class ofxTPSpriteData {
public:
    ofxTPSpriteData();
    
    void setName(const string& theName);
    string getName() const;
    void determineAnimated();
    void extractFrame();
    int getFrame() const;
    bool getRotated() const;
    void setRotated(const string & isRotated);
    
    // Members
    string name;
    string animationName;
    int x;
    int y;
    int w;
    int h;
    int oX;
    int oY;
    int oW;
    int oH;
    bool rotated;
    
    unsigned int frame;
    bool isAnimated;
};

inline void ofxTPSpriteData::setName(const string& theName) {
    name = theName;
    determineAnimated();
}

inline string ofxTPSpriteData::getName() const {
    return name;
}

inline int ofxTPSpriteData::getFrame() const {
    return frame;
}

inline bool ofxTPSpriteData::getRotated() const {
    return rotated;
}

inline void ofxTPSpriteData::setRotated(const string & isRotated) {
    rotated = (isRotated == "y");
}


#endif /* defined(__ofxTPSpriteData__) */
