// ------------------------------------------------------------------
// ofxTexturePacker.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#pragma once

#include <iostream>
#include "ofMain.h"
#include "ofxTPLoader.h"
#include "ofxTPSpriteCore.h"
#include "ofxTPAnimatedSprite.h"
#include "ofxTPSprite.h"

#include "math.h"

/**
 Example exported Texture Packer "Generic XML"
 <!--Format:
 n  => name of the sprite
 x  => sprite x pos in texture
 y  => sprite y pos in texture
 w  => sprite width (may be trimmed)
 h  => sprite height (may be trimmed)
 oX => sprite's x-corner offset (only available if trimmed)
 oY => sprite's y-corner offset (only available if trimmed)
 oW => sprite's original width (only available if trimmed)
 oH => sprite's original height (only available if trimmed)
 r => 'y' only set if sprite is rotated
 -->
 <TextureAtlas imagePath="template.png" width="966" height="1782">
 <sprite n="Default-568h@2x~iphone.png" x="2" y="644" w="640" h="1136"/>
 <sprite ...>
 </TextureAtlas>
 */

//--------------------------------------------------

class ofxTexturePacker;
typedef shared_ptr<ofxTexturePacker> ofxTexturePackerPtr;

class ofxTexturePacker {
public:
    ofxTexturePacker();
    ~ofxTexturePacker();
    
    bool load(const string& fileToLoad, bool bLoadTexture=true);
    
    void drawTest();
    vector<string> getSpriteNames();
    vector<string> getAnimationNames();
    
    ofxTPSpritePtr getSprite(const string& spriteName);
    ofxTPAnimatedSpritePtr getAnimatedSprite(const string& spriteName);
    
    void setDebugMode(bool debugMode);
    
    shared_ptr<ofTexture> getTexture();
    const string getTextureFilePath() const;
    void setTexture(shared_ptr<ofTexture> newTexture);
    
protected:

    vector<ofxTPSpritePtr> sprites;
    vector<ofxTPAnimatedSpritePtr> animatedSprites;
    shared_ptr<ofTexture> texture;
    ofxTPLoaderPtr loader;
    bool bDebugMode;
    
    void createLoader();
    void removeLoader();
    void removeTexture();
};

inline shared_ptr<ofTexture> ofxTexturePacker::getTexture() {
    return texture;
}

inline const string ofxTexturePacker::getTextureFilePath() const {
    string textureLocation = "";
    string directory = ofFilePath::getEnclosingDirectory(loader->getFileXMLPath(), false);
    bool isTextureWithXML = ofFile::doesFileExist((directory + loader->getImagePath()));
    if(isTextureWithXML) {
        textureLocation = directory + loader->getImagePath();
    } else {
        textureLocation = loader->getImagePath();
    }
    return textureLocation;
}


