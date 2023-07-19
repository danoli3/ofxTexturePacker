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

#include <regex>
//#include "regex.h"  // posix


class ofxTPSpriteData;
typedef shared_ptr<ofxTPSpriteData> ofxTPSpriteDataPtr;

class ofxTPSpriteData {
public:
    ofxTPSpriteData();
    
    void setup();
    void setName(const string& theName);
    void setAnimationName(const string& sAnimationName);
    
    void determineAnimated();
    void determineRotated(const string & isRotated);
    void extractFrame();
    
    void setX(int sX);
    void setY(int sY);
    void setW(int sWidth);
    void setH(int sHeight);
    void setPX(float sPX);
    void setPY(float sPY);
    void setWidth(int sWidth);
    void setHeight(int sHeight);
    void setOffsetX(int soX);
    void setOffsetY(int soY);
    void setOffsetWidth(int soWidth);
    void setOffsetHeight(int soHeight);
    void setDebugMode(bool debug);
    
    const string& getName() const;
    const string& getAnimationName() const;
    int getX() const;
    int getY() const;
    int getW() const;
    int getH() const;
    float getPX() const;
    float getPY() const;
    int getOffsetX() const;
    int getOffsetY() const;
    int getOffsetWidth() const;
    int getOffsetHeight() const;
    int getFrame() const;
    
    bool isRotated() const;
    bool hasPivot() const;
    bool isAnimated() const;
    bool isTrimmed() const;
    bool isDebugMode() const;
    
    int getWidth() const;
    int getHeight() const;
    
protected:
    string name;          // => name of the sprite
    string animationName; // => name of the animation
    
    int x;  // x => sprite x pos in texture
    int y;  // y => sprite x pos in texture
    int w;  // w => sprite y pos in texture
    int h;  // h => sprite height (may be trimmed)
    float pX; // pX => x pos of the pivot point (relative to sprite width)
    float pY; // pY => y pos of the pivot point (relative to sprite height)
    int oX; // oX => x pos of the pivot point (relative to sprite width)
    int oY; // oY => sprite's y-corner offset (only available if trimmed)
    int oW; // oW => sprite's original width (only available if trimmed)
    int oH; // oH => sprite's original height (only available if trimmed)
    unsigned int frame; // frame => the frame number in an animation
    bool bRotated;      // bRotated  => 'true' only set if sprite is rotated (-90)
    
    bool bAnimated;     // bAnimated => bool
    bool bPivot;        // bPivot => has a pivot point set
    bool bTrimmed;      // bTrimmed => texture trimmed
    
    bool bDebugMode;
};

inline void ofxTPSpriteData::determineRotated(const string & isRotated) {
    bRotated = (isRotated == "y")?true:false;
}

inline void ofxTPSpriteData::setName(const string& theName) {
    name = theName;
    determineAnimated();
}
//--------- Setters
inline void ofxTPSpriteData::setAnimationName(const string& sAnimationName) { animationName = sAnimationName; }
inline void ofxTPSpriteData::setX(int sX) { x = sX; }
inline void ofxTPSpriteData::setY(int sY) { y = sY; }
inline void ofxTPSpriteData::setW(int sWidth) { w = sWidth; }
inline void ofxTPSpriteData::setH(int sHeight) { h = sHeight; }
inline void ofxTPSpriteData::setPX(float sPX) { pX = sPX; }
inline void ofxTPSpriteData::setPY(float sPY) { pY = sPY; }
inline void ofxTPSpriteData::setWidth(int sWidth) { w = sWidth; }
inline void ofxTPSpriteData::setHeight(int sHeight) { h = sHeight; }
inline void ofxTPSpriteData::setOffsetX(int soX) { oX = soX; }
inline void ofxTPSpriteData::setOffsetY(int soY) { oY = soY; }
inline void ofxTPSpriteData::setOffsetWidth(int soWidth) { oW = soWidth; }
inline void ofxTPSpriteData::setOffsetHeight(int soHeight) { oH = soHeight; }
inline void ofxTPSpriteData::setDebugMode(bool debug) { bDebugMode = debug; }
//--------- Getters
inline const string& ofxTPSpriteData::getName() const { return name; }
inline const string& ofxTPSpriteData::getAnimationName() const { return animationName; }
inline int ofxTPSpriteData::getX() const { return x; }
inline int ofxTPSpriteData::getY() const { return y; }
inline int ofxTPSpriteData::getW() const { return w; }
inline int ofxTPSpriteData::getH() const { return h; }
inline float ofxTPSpriteData::getPX() const { return pX; }
inline float ofxTPSpriteData::getPY() const { return pY; }
inline int ofxTPSpriteData::getOffsetX() const { return oX; }
inline int ofxTPSpriteData::getOffsetY() const { return oY; }
inline int ofxTPSpriteData::getOffsetWidth() const { return oW; }
inline int ofxTPSpriteData::getOffsetHeight() const { return oH; }
inline int ofxTPSpriteData::getFrame() const { return frame; }
inline bool ofxTPSpriteData::isRotated() const { return bRotated; }
inline bool ofxTPSpriteData::isAnimated() const { return bAnimated; }
inline bool ofxTPSpriteData::hasPivot() const { return bPivot; }
inline bool ofxTPSpriteData::isTrimmed() const { return bTrimmed; }
inline bool ofxTPSpriteData::isDebugMode() const { return bDebugMode; }

inline int ofxTPSpriteData::getWidth() const {
    if(isRotated()) {
        return getOffsetHeight();
    } else {
        return getOffsetWidth();
    }
}
inline int ofxTPSpriteData::getHeight() const {
    if(isRotated()) {
        return getOffsetWidth();
    } else {
        return getOffsetHeight();
    }
}

