// ------------------------------------------------------------------
// ofxTPAnimatedSprite.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#include "ofxTPAnimatedSprite.h"


ofxTPAnimatedSprite::ofxTPAnimatedSprite() : name(""), frame(0), loopType(OF_LOOP_NORMAL) {
    
}

void ofxTPAnimatedSprite::draw(int x, int y) {
    unsigned int currentFrameIndex = getCurrentFrame();
    unsigned int allFramesIndex = frames.size();
    if(frames.size() == 0 || currentFrameIndex > allFramesIndex) {
        ofLog(OF_LOG_ERROR, "ofxTPAnimatedSprite::draw:: Current Frame is out of index for loaded AnimatedSprite");
        return;
    } else {
        frames[currentFrameIndex]->draw(x, y);
    }
}

void ofxTPAnimatedSprite::update() {
    bNewFrame = false;
    
    if(isPlaying() == false) {
        return;
    }
    
    nextFrame();
}

string ofxTPAnimatedSprite::getName() const {
    return name;
}

ofxTPSprite* ofxTPAnimatedSprite::getCurrentSprite() {
    unsigned int currentFrameIndex = getCurrentFrame();
    unsigned int allFramesIndex = frames.size();
    if(frames.size() == 0 || currentFrameIndex > allFramesIndex) {
        ofLog(OF_LOG_ERROR, "ofxTPAnimatedSprite::getCurrentSprite Current Frame is out of index for loaded AnimatedSprite");
        return NULL;
    } else {
        return frames[currentFrameIndex];
    }
}


void ofxTPAnimatedSprite::play() {
    
    if(getIsMovieDone()) {
        setFrame(0);
    }
    
    bPlaying = true;
    bPaused = false;
}

void ofxTPAnimatedSprite::stop() {
    bPlaying = false;
    bPaused = false;
}

bool ofxTPAnimatedSprite::isPaused() {
    return bPaused;
}

bool ofxTPAnimatedSprite::isPlaying() {
    return bPlaying;
}

float ofxTPAnimatedSprite::getPosition() {
    return position;
}

float ofxTPAnimatedSprite::getSpeed() {
    return speed;
}

float ofxTPAnimatedSprite::getDuration() {
    return duration;
}

bool ofxTPAnimatedSprite::getIsMovieDone() {
    bool bFinished = (bPlaying == false) && (getCurrentFrame() == frameLast);
    return bFinished;
}

void ofxTPAnimatedSprite::setPaused(bool bPause) {
    bPaused = bPause;
}

void ofxTPAnimatedSprite::setPosition(float value) {
    int index = value * frameLast;
    setFrame(index);
}

void ofxTPAnimatedSprite::setVolume(float volume) {
    // not supported.
}

void ofxTPAnimatedSprite::setLoopState(ofLoopType value) {
    loopType = value;
}

void ofxTPAnimatedSprite::setSpeed(float value) {
    speed = value;
}

void ofxTPAnimatedSprite::setFrame(int value) {
    int index = ofClamp(value, 0, frameLast);
    if(frame == index) {
        return;
    }
    frame = index;
    bNewFrame = true;
    
    position = frame / (float)frameLast;
}

int	ofxTPAnimatedSprite::getCurrentFrame() {
    return frame;
}

int	ofxTPAnimatedSprite::getTotalNumFrames() {
    return framesTotal;
}

ofLoopType ofxTPAnimatedSprite::getLoopState() {
    return loopType;
}

void ofxTPAnimatedSprite::firstFrame() {
    setFrame(0);
}

void ofxTPAnimatedSprite::nextFrame() {
    int index = getCurrentFrame() + 1;
    if(index > frameLast) {
        if(loopType == OF_LOOP_NONE) {
            index = frameLast;
            if(isPlaying()) {
                stop();
            }
        } else if(loopType == OF_LOOP_NORMAL) {
            index = 0;
        } else if(loopType == OF_LOOP_PALINDROME) {
            // TODO.
        }
    }
    
    setFrame(index);
}

void ofxTPAnimatedSprite::previousFrame() {
    int index = getCurrentFrame() - 1;
    if(index < 0) {
        if(loopType == OF_LOOP_NONE) {
            index = 0;
        } else if(loopType == OF_LOOP_NORMAL) {
            index = frameLast;
        } else if(loopType == OF_LOOP_PALINDROME) {
            // TODO.
        }
    }
    
    setFrame(index);
}
