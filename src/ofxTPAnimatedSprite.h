// ------------------------------------------------------------------
// ofxAnimatedSprites.h
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#pragma once

#ifndef __ofxTPAnimatedSprite__
#define __ofxTPAnimatedSprite__

#include "ofMain.h"
#include "ofxTPSpriteCore.h"
#include "ofxTPTypes.h"
#include "ofxTPSprite.h"

class ofxTPAnimatedSprite : public ofxTPSpriteCore {
public:
    ofxTPAnimatedSprite();
    
    void draw(int x, int y);
    void update();
    
    void setName(const string& theName);
    string getName() const;
    
    void addSprite(ofxTPSprite * sprite);
    ofxTPSprite* getCurrentSprite();
    
    
    void play();
    void stop();
    
    bool isPaused();

    bool isPlaying();
    float getPosition();
    float getSpeed();
    float getDuration();
    bool getIsMovieDone();

    void setPaused(bool bPause);
    void setPosition(float pct);
    void setVolume(float volume); // 0..1
    void setLoopState(ofLoopType state);
    void setSpeed(int speed);
    void setFrame(int frame);  // frame 0 = first frame...

    int	getCurrentFrame();
    int	getTotalNumFrames();
    ofLoopType getLoopState();

    void firstFrame();
    void nextFrame();
    void previousFrame();
    
protected:
    string name;
    unsigned int frame;
    unsigned int frameLast;
    unsigned int framesTotal;
    
    float position;
    int speed;
    float duration;
    ofLoopType loopType;
    bool bPlaying;
    bool bPaused;
    bool bNewFrame;
    
    //! frame is a vector of all ofxTPSprites for this Animated Sprite Sequence. Memory managed by ofxTexturePacker.
    vector<ofxTPSprite*> frames;
};

inline void ofxTPAnimatedSprite::setName(const string& theName) {
    name = theName;
}


#endif /* defined(__ofxTPAnimatedSprite__) */
