// ------------------------------------------------------------------
// ofxTPLoader.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#include "ofxTPLoader.h"

ofxTPLoader::ofxTPLoader() {
    
}

ofxTPLoader::~ofxTPLoader() {
    
}

vector<ofxTPSpriteData*> ofxTPLoader::load(const string fileName) {
    if( XML.loadFile(fileName) ){
        ofLog(OF_LOG_NOTICE, fileName+ " loaded!");
    } else{
        ofLog(OF_LOG_ERROR, " unable to load " + fileName + " check data/ folder");
    }
    
    unsigned int isTextureAtlas = XML.getNumTags("TextureAtlas");
    vector<ofxTPSpriteData*> sprites;
    
    if(isTextureAtlas != 0) {
        
        string a = XML.getAttribute("TextureAtlas", "imagePath", "");
        vector<string> names;
        XML.getAttributeNames("TextureAtlas", names);
        if(names.size() != 0) {
            for(unsigned int i = 0; i<=names.size()-1; i++) {
                ofLog(OF_LOG_VERBOSE, names[i]);
            }
        }
        
        textureAtlas.imagePath = XML.getAttribute("TextureAtlas", "imagePath", "");
        textureAtlas.width = XML.getAttribute("TextureAtlas", "width", 0);
        textureAtlas.height = XML.getAttribute("TextureAtlas", "height", 0);
        
        XML.pushTag("TextureAtlas", 0);
        unsigned int numberOfSprites = XML.getNumTags("sprite");
        if(numberOfSprites > 0){
            
            vector<string> names;
            XML.getAttributeNames("sprite", names);
            if(names.size() != 0) {
                for(unsigned int i = 0; i<=names.size()-1; i++) {
                    ofLog(OF_LOG_VERBOSE, names[i]);
                }
            }
            
            unsigned int maxSpritesRead = MIN(numberOfSprites, 100); // @todo vector size
            for(int i = 0; i < maxSpritesRead; i++){
                ofxTPSpriteData * sprite = new ofxTPSpriteData();
                sprite->setName(XML.getAttribute("sprite", "n", "", i));
                sprite->x = XML.getAttribute("sprite", "x", 0, i);
                sprite->y = XML.getAttribute("sprite", "y", 0, i);
                sprite->w = XML.getAttribute("sprite", "w", 0, i);
                sprite->h = XML.getAttribute("sprite", "h", 0, i);
                sprite->oX = XML.getAttribute("sprite", "oX", 0, i);
                sprite->oY = XML.getAttribute("sprite", "oY", 0, i);
                sprite->oW = XML.getAttribute("sprite", "oW", 0, i);
                sprite->oH = XML.getAttribute("sprite", "oH", 0, i);
                sprite->setRotated(XML.getAttribute("sprite", "r", "", i));
                sprites.push_back(sprite);
            }
        }
        XML.popTag();
    }
    return sprites;
}

void ofxTPLoader::clearXML() {
    XML.clear();
}
