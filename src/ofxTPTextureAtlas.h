// ------------------------------------------------------------------
// ofxTPTextureAtlas.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#ifndef OSXProject_ofxTPTextureAtlas_h
#define OSXProject_ofxTPTextureAtlas_h

#include "ofMain.h"

class ofxTPTextureAtlas {
public:
    ofxTPTextureAtlas() : imagePath(""), width(0), height(0) { }
    string getImagePath() const;
    string imagePath;
    int width;
    int height;
};

inline string ofxTPTextureAtlas::getImagePath() const {
    return imagePath;
}


#endif
