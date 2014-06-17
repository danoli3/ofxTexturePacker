// ------------------------------------------------------------------
// ofxTexturePacker.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#pragma once

#ifndef __ofxTexturePacker__
#define __ofxTexturePacker__

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

class ofxTexturePacker {
public:
    ofxTexturePacker();
    ~ofxTexturePacker();
    
    bool load(const string& fileToLoad);
    void drawTest();
    
    ofxTPSprite* getSprite(const string& spriteName);
    ofxTPAnimatedSprite* getAnimatedSprite(const string& spriteName);
    
protected:
    vector<ofxTPSprite*> sprites;
    vector<ofxTPAnimatedSprite*> animatedSprites;
    ofTexture* texture;
    ofxTPLoader loader;
};

#endif /* defined(__ofxTexturePacker__) */
