// ------------------------------------------------------------------
// ofxTPTextureAtlas.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#pragma once
#include "ofMain.h"

class ofxTPTextureAtlas {
public:
    ofxTPTextureAtlas() : imagePath(""), w(0), h(0) {
        
    }
    void setWidth(const int& sWidth);
    void setHeight(const int& sHeight);
    void setImagePath(const string& sImagePath);
    
    int getWidth() const;
    int getHeight() const;
    const string& getImagePath() const;

private:
    string imagePath;
    int w;
    int h;
};

//----------- Setters
inline void ofxTPTextureAtlas::setWidth(const int& sWidth) { w = sWidth; }
inline void ofxTPTextureAtlas::setHeight(const int& sHeight) { h = sHeight; }
inline void ofxTPTextureAtlas::setImagePath(const string& sImagePath) { imagePath = sImagePath; }
//----------- Getters
inline int ofxTPTextureAtlas::getWidth() const { return w; }
inline int ofxTPTextureAtlas::getHeight() const { return h; }
inline const string& ofxTPTextureAtlas::getImagePath() const { return imagePath; }

