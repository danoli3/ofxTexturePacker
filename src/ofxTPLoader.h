// ------------------------------------------------------------------
// ofxTPLoader.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#pragma once

#ifndef __ofxTPLoader__
#define __ofxTPLoader__

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxTPSpriteData.h"
#include "ofxTPTextureAtlas.h"


class ofxTPLoader {
public:
    
    ofxTPLoader();
    ~ofxTPLoader();
    
    vector<ofxTPSpriteData*> load(const string fileName);
    
    string getImagePath() const;
    
    void clearXML();
    
    ofxTPTextureAtlas textureAtlas;
    ofxXmlSettings XML;
    
    bool bLoaded;
};

inline string ofxTPLoader::getImagePath() const {
    return textureAtlas.getImagePath();
}

#endif /* defined(__ofxTPLoader__) */
