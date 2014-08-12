// ------------------------------------------------------------------
// ofxTPSpriteData.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#pragma once
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
    void setAnimationName(const string& sAnimationName);
    
    void determineAnimated();
    void determineRotated(const string & isRotated);
    void extractFrame();
    
    void setX(const int& sX);
    void setY(const int& sY);
    void setW(const int& sWidth);
    void setH(const int& sHeight);
    void setWidth(const int& sWidth);
    void setHeight(const int& sHeight);
    void setOffsetX(const int& soX);
    void setOffsetY(const int& soY);
    void setOffsetWidth(const int& soWidth);
    void setOffsetHeight(const int& soHeight);
    
    const string& getName() const;
    const string& getAnimationName() const;
    int getX() const;
    int getY() const;
    int getW() const;
    int getH() const;
    int getWidth() const;
    int getHeight() const;
    int getOffsetX() const;
    int getOffsetY() const;
    int getOffsetWidth() const;
    int getOffsetHeight() const;
    int getFrame() const;
    bool getRotated() const;
    bool getAnimated() const;
    
protected:
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

inline void ofxTPSpriteData::determineRotated(const string & isRotated) {
    rotated = (isRotated == "y");
}

inline void ofxTPSpriteData::setName(const string& theName) {
    name = theName;
    determineAnimated();
}
//--------- Setters
inline void ofxTPSpriteData::setAnimationName(const string& sAnimationName) { animationName = sAnimationName; }
inline void ofxTPSpriteData::setX(const int& sX) { x = sX; }
inline void ofxTPSpriteData::setY(const int& sY) { y = sY; }
inline void ofxTPSpriteData::setW(const int& sWidth) { w = sWidth; }
inline void ofxTPSpriteData::setH(const int& sHeight) { h = sHeight; }
inline void ofxTPSpriteData::setWidth(const int& sWidth) { w = sWidth; }
inline void ofxTPSpriteData::setHeight(const int& sHeight) { h = sHeight; }
inline void ofxTPSpriteData::setOffsetX(const int& soX) { oX = soX; }
inline void ofxTPSpriteData::setOffsetY(const int& soY) { oY = soY; }
inline void ofxTPSpriteData::setOffsetWidth(const int& soWidth) { oW = soWidth; }
inline void ofxTPSpriteData::setOffsetHeight(const int& soHeight) { oH = soHeight; }
//--------- Getters
inline const string& ofxTPSpriteData::getName() const { return name; }
inline const string& ofxTPSpriteData::getAnimationName() const { return animationName; }
inline int ofxTPSpriteData::getX() const { return x; }
inline int ofxTPSpriteData::getY() const { return y; }
inline int ofxTPSpriteData::getW() const { return w; }
inline int ofxTPSpriteData::getH() const { return h; }
inline int ofxTPSpriteData::getWidth() const { return getOffsetWidth(); }
inline int ofxTPSpriteData::getHeight() const { return getOffsetHeight(); }
inline int ofxTPSpriteData::getOffsetX() const { return oX; }
inline int ofxTPSpriteData::getOffsetY() const { return oY; }
inline int ofxTPSpriteData::getOffsetWidth() const { return oW; }
inline int ofxTPSpriteData::getOffsetHeight() const { return oH; }
inline int ofxTPSpriteData::getFrame() const { return frame; }
inline bool ofxTPSpriteData::getRotated() const { return rotated; }
inline bool ofxTPSpriteData::getAnimated() const { return isAnimated; }

