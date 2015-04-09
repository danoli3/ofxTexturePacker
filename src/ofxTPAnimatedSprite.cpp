// ------------------------------------------------------------------
// ofxTPAnimatedSprite.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------

#include "ofxTPAnimatedSprite.h"


ofxTPAnimatedSprite::ofxTPAnimatedSprite() : name(""), frame(0), loopType(OF_LOOP_NORMAL), speed(24), frameRate(0.0f), frameTracker(0.0f) {
    bPlaying = true;
    bPlayingReverse = false;
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
    float elapsed = ofGetLastFrameTime();
    if(elapsed <= 0) {
        return;
    }
    frameTracker += elapsed;
    if(frameTracker >= elapsed * frameRate) {
        frameTracker = 0.0f;
        if(bPlayingReverse) {
            previousFrame();
        } else {
            nextFrame();
        }
    }
}

void ofxTPAnimatedSprite::addSprite(ofxTPSpritePtr sprite) {
    frames.push_back(sprite);
    frameLast = frames.size()-1;
    framesTotal = frames.size();
}

ofxTPSpritePtr ofxTPAnimatedSprite::getCurrentSprite() {
    unsigned int currentFrameIndex = getCurrentFrame();
    unsigned int allFramesIndex = frames.size();
    if(frames.size() == 0 || currentFrameIndex > allFramesIndex) {
        ofLog(OF_LOG_ERROR, "ofxTPAnimatedSprite::getCurrentSprite Current Frame is out of index for loaded AnimatedSprite");
        return ofxTPSpritePtr();
    } else {
        return frames[currentFrameIndex];
    }
}

void ofxTPAnimatedSprite::play() {
    
    if(getIsAnimationDone()) {
        setFrame(0);
    }
    
    bPlaying = true;
    bPaused = false;
}

void ofxTPAnimatedSprite::stop() {
    bPlaying = false;
    bPaused = false;
}

bool ofxTPAnimatedSprite::isPaused() const {
    return bPaused;
}

bool ofxTPAnimatedSprite::isPlaying() const {
    return bPlaying;
}

float ofxTPAnimatedSprite::getPosition() const {
    return position;
}

float ofxTPAnimatedSprite::getSpeed() const {
    return speed;
}

float ofxTPAnimatedSprite::getDuration() const {
    return duration;
}

bool ofxTPAnimatedSprite::getIsAnimationDone() const {
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

void ofxTPAnimatedSprite::setSpeed(int value) {
    speed = value;
    if(speed > 0) {
        frameRate = ofGetFrameRate() / float(speed);
    }
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

int	ofxTPAnimatedSprite::getCurrentFrame() const {
    return frame;
}

int	ofxTPAnimatedSprite::getTotalNumFrames() const {
    return framesTotal;
}

ofLoopType ofxTPAnimatedSprite::getLoopState() const {
    return loopType;
}

void ofxTPAnimatedSprite::firstFrame() {
    setFrame(0);
}

float ofxTPAnimatedSprite::getWidth(){
    return getCurrentSprite()->getData()->getWidth();
}

float ofxTPAnimatedSprite::getHeight(){
    return getCurrentSprite()->getData()->getHeight();
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
        }
    }
    setFrame(index);
}

void ofxTPAnimatedSprite::setTexture(shared_ptr<ofTexture> tex){
    if(frames.size() != 0) {
        unsigned int frameSize = frames.size()-1;
        for(unsigned int i=0; i<=frameSize; i++) {
            ofxTPSpritePtr sprite = frames[i];
            if(sprite) {
                sprite->setTexture(tex);
            }
        }
    }
}


void ofxTPAnimatedSprite::setDebugMode(bool debugMode) {
    if(frames.size() != 0) {
        unsigned int frameSize = frames.size()-1;
        for(unsigned int i=0; i<=frameSize; i++) {
            ofxTPSpritePtr sprite = frames[i];
            if(sprite) {
                sprite->setDebugMode(debugMode);
            }
        }
    }
}
