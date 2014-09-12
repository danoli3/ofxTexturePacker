// ------------------------------------------------------------------
// ofxTPSpriteData.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#include "ofxTPSpriteData.h"

ofxTPSpriteData::ofxTPSpriteData() : name(""), animationName(""), x(0), y(0), w(0), h(0), oX(0), oY(0), oW(0), oH(0), frame(0), isAnimated(false) {
    
}

void ofxTPSpriteData::determineAnimated() {
    Poco::RegularExpression reg("((?:(?![\\d]*[.].*$)[\\w\\s])+)([\\d]*)([.].*)$");
//    int match(const std::string& subject, Match& mtch, int options = 0) const;
    Poco::RegularExpression::MatchVec matches;
    int numberOfMatches = reg.match(name, 0, matches);
    if(!matches.empty()){
        if(matches[0].length != 0) {
            if (matches[2].length > 0) {
                if (matches[1].length > 0) {
                    animationName = name.substr(matches[1].offset, matches[1].length);
                    if(animationName.substr(animationName.size()-1, animationName.size()) == "_") {
                        animationName = animationName.substr(0, animationName.size()-1);
                    }
                }
                isAnimated = true;
                frame = ofToInt(name.substr(matches[2].offset, matches[2].length));
            } else {
                isAnimated = false;
            }
        }
        else {
            ofLog(OF_LOG_ERROR, "ERROR: Filename format not recognised for " + name);
        }
    } else {
        // Make sure not to Trim names in Texture Packer! if you debug your way here!
        isAnimated = false;
    }
//---------- CP-11 version
/** 
    if (reg.match(name, matches)) {
        if (subStrings.length(2) > 0) {
            if (subStrings.length(1) > 0) {
                animationName = subStrings[1];
            }
            isAnimated = true;
            frame = ofToInt(subStrings[2]);
        } else {
            isAnimated = false;
        }
    } else {
        ofLog(OF_LOG_ERROR, "ERROR: Filename format not recognised for " + name);
    }

    smatch subStrings;
    regex expression ("((?:(?![\\d]*[.].*$)[\\w\\s])+)([\\d]*)([.].*)$");
    
    if (regex_match(name, subStrings, expression)) {
        if (subStrings.length(2) > 0) {
            if (subStrings.length(1) > 0) {
                animationName = subStrings[1];
            }
            isAnimated = true;
            frame = ofToInt(subStrings[2]);
        } else {
            isAnimated = false;
        }
    } else {
        ofLog(OF_LOG_ERROR, "ERROR: Filename format not recognised for " + name);
    }
*/

}

void ofxTPSpriteData::extractFrame() {
    
}