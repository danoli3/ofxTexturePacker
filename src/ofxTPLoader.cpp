// ------------------------------------------------------------------
// ofxTPLoader.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#include "ofxTPLoader.h"

ofxTPLoader::ofxTPLoader() : XML(new ofxXmlSettings()), textureAtlas(new ofxTPTextureAtlas()), fileXMLPath("") {
}

ofxTPLoader::~ofxTPLoader() {
    if(textureAtlas) {
        delete textureAtlas;
        textureAtlas = NULL;
    }
    if(XML) {
        delete XML;
        XML = NULL;
    }
}

vector<ofxTPSpriteData*> ofxTPLoader::load(const string fileName) {
    fileXMLPath = fileName;
    if( XML->loadFile(fileXMLPath) ){
        ofLog(OF_LOG_VERBOSE, fileXMLPath+ " loaded!");
    } else{
        ofLog(OF_LOG_ERROR, " unable to load " + fileXMLPath + " check data/ folder");
    }
    
    unsigned int isTextureAtlas = XML->getNumTags("TextureAtlas");
    vector<ofxTPSpriteData*> sprites;
    
    if(isTextureAtlas != 0) {
        string a = XML->getAttribute("TextureAtlas", "imagePath", "");
        vector<string> names;
        XML->getAttributeNames("TextureAtlas", names);
        if(names.size() != 0) {
            for(unsigned int i = 0; i<=names.size()-1; i++) {
                ofLog(OF_LOG_VERBOSE, names[i]);
            }
        }
        
        textureAtlas->setImagePath(XML->getAttribute("TextureAtlas", "imagePath", ""));
        textureAtlas->setWidth(XML->getAttribute("TextureAtlas", "width", 0));
        textureAtlas->setHeight(XML->getAttribute("TextureAtlas", "height", 0));
        
        XML->pushTag("TextureAtlas", 0);
        unsigned int numberOfSprites = XML->getNumTags("sprite");
        if(numberOfSprites > 0){
            vector<string> names;
            XML->getAttributeNames("sprite", names);
            if(names.size() != 0) {
                for(unsigned int i = 0; i<=names.size()-1; i++) {
                    ofLog(OF_LOG_VERBOSE, names[i]);
                }
            }
            for(int i = 0; i < numberOfSprites; i++){
                ofxTPSpriteData * sprite = new ofxTPSpriteData();
                sprite->setName(XML->getAttribute("sprite", "n", "", i));
                sprite->setX(XML->getAttribute("sprite", "x", 0, i));
                sprite->setY(XML->getAttribute("sprite", "y", 0, i));
                sprite->setW(XML->getAttribute("sprite", "w", 0, i));
                sprite->setH(XML->getAttribute("sprite", "h", 0, i));
                sprite->setPX(XML->getAttribute("sprite", "pX", 0, i));
                sprite->setPY(XML->getAttribute("sprite", "pY", 0, i));
                sprite->setOffsetX(XML->getAttribute("sprite", "oX", 0, i));
                sprite->setOffsetY(XML->getAttribute("sprite", "oY", 0, i));
                sprite->setOffsetWidth(XML->getAttribute("sprite", "oW",  sprite->getW(), i));
                sprite->setOffsetHeight(XML->getAttribute("sprite", "oH", sprite->getH(), i));
                sprite->determineRotated(XML->getAttribute("sprite", "r", "", i));
                sprite->setup();
                sprites.push_back(sprite);
            }
        }
        XML->popTag();
    }
    return sprites;
}

void ofxTPLoader::clearXML() {
    XML->clear();
}
