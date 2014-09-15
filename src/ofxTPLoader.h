// ------------------------------------------------------------------
// ofxTPLoader.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxTPSpriteData.h"
#include "ofxTPTextureAtlas.h"


class ofxTPLoader {
public:
    
    ofxTPLoader();
    ~ofxTPLoader();
    
    vector<ofxTPSpriteData*> load(const string fileName);
    const string& getImagePath() const;
    const string& getFileXMLPath() const;
    void clearXML();
    

    
    ofxTPTextureAtlas * textureAtlas;
    
protected:
    ofxXmlSettings * XML;
    
    string fileXMLPath;
    bool bLoaded;
};

inline const string& ofxTPLoader::getImagePath() const {
    return textureAtlas->getImagePath();
}

inline const string& ofxTPLoader::getFileXMLPath() const {
    return fileXMLPath;
}



