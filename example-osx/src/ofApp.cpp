#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    tpRotatedTrim = ofxTexturePackerPtr(new ofxTexturePacker());
    tpRotatedTrim->load("texture/rotated-trim.xml");
    tpRotatedTrim->setDebugMode(true);
    sprite = tpRotatedTrim->getSprite("Box2.png");
    
    //------------------
    tpRotatedTrimAnimation = tpRotatedTrim->getAnimatedSprite("CapGuyWalk");
    if(tpRotatedTrimAnimation != NULL) {
        tpRotatedTrimAnimation->setSpeed(24);
        tpRotatedTrimAnimation->play();
    } else {
        ofLog(OF_LOG_FATAL_ERROR, "ofApp::setup():: Could not load animated sprite");
    }
    
    //------------------
    tpRotatedNoTrim = ofxTexturePackerPtr(new ofxTexturePacker());
    tpRotatedNoTrim->load("texture/rotated-trim.xml");
    tpRotatedNoTrim->setDebugMode(true);
    tpRotatedNoTrimAnimation = tpRotatedNoTrim->getAnimatedSprite("CapGuyWalk");
    if(tpRotatedNoTrimAnimation != NULL) {
        tpRotatedNoTrimAnimation->setSpeed(24);
        tpRotatedNoTrimAnimation->play();
    } else {
        ofLog(OF_LOG_FATAL_ERROR, "ofApp::setup():: Could not load animated sprite");
    }
    
    tpTrim = ofxTexturePackerPtr(new ofxTexturePacker());
    tpTrim->load("texture/trim.xml");
    tpTrimAnimation = tpTrim->getAnimatedSprite("CapGuyWalk");
    tpTrim->setDebugMode(true);
    if(tpTrimAnimation != NULL) {
        tpTrimAnimation->setSpeed(24);
        tpTrimAnimation->play();
    } else {
        ofLog(OF_LOG_FATAL_ERROR, "ofApp::setup():: Could not load animated sprite");
    }
    
    tpNoTrim = ofxTexturePackerPtr(new ofxTexturePacker());
    tpNoTrim->load("texture/notrim.xml");
    tpNoTrim->setDebugMode(false);
    tpNoTrimAnimation = tpNoTrim->getAnimatedSprite("CapGuyWalk");
    if(tpNoTrimAnimation != NULL) {
        tpNoTrimAnimation->setSpeed(24);
        tpNoTrimAnimation->play();
    } else {
        ofLog(OF_LOG_FATAL_ERROR, "ofApp::setup():: Could not load animated sprite");
    }
    
}

void ofApp::exit() {
    
    tpRotatedTrim.reset();
    tpRotatedNoTrim.reset();
    tpNoTrim.reset();
    tpTrim.reset();
}

//--------------------------------------------------------------
void ofApp::update(){
    if(tpRotatedTrimAnimation) {
        tpRotatedTrimAnimation->update();
    }
    
    if(tpRotatedNoTrimAnimation) {
        tpRotatedNoTrimAnimation->update();
    }
    
    if(tpTrimAnimation) {
        tpTrimAnimation->update();
    }
    
    if(tpNoTrimAnimation) {
        tpNoTrimAnimation->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //--------- Draws the ofxTexturePacker logo gif
    sprite->draw(50,0);
    
    if(tpRotatedTrimAnimation){
        ofPushMatrix();
        ofTranslate(300*2, 180);
        ofPushStyle();
        ofSetColor(255, 0, 0);
        ofDrawBitmapString("BUGGED (moves down in rotate)", 10, -40);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Rotation + Trim", 10, -20);
        ofPopStyle();
        ofPopMatrix();
        
        
        tpRotatedTrimAnimation->draw(300*2, 180);
        
        
    }
    
    if(tpRotatedNoTrimAnimation){
        ofPushMatrix();
        ofTranslate(300*3, 180);
        ofPushStyle();
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Rotation + No Trim", 10, -20);
        ofSetColor(255, 0, 0);
        ofDrawBitmapString("BUGGED (moves down in rotate)", 10, -40);
        ofPopStyle();
        ofPopMatrix();
        
        
        tpRotatedNoTrimAnimation->draw(300*3, 180);
        
    }
    
    if(tpTrimAnimation){
     
        ofPushStyle();
        ofSetColor(255, 255, 255,64);
        tpTrimAnimation->draw(300*2, 180);
        ofPopStyle();
        
        
    }
    
    if(tpTrimAnimation){
        ofPushMatrix();
        ofTranslate(300, 180);
        ofPushStyle();
        ofSetColor(0, 255, 0);
        ofDrawBitmapString("Perfect", 10, -40);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Trim", 10, -20);
        ofPopStyle();
        ofPopMatrix();
        
        tpTrimAnimation->draw(300, 180);
        
       
    }
    
    if(tpNoTrimAnimation){
        ofPushMatrix();
        ofTranslate(10, 180);
        ofPushStyle();
        ofSetColor(0, 255, 0);
        ofDrawBitmapString("Perfect", 10, -40);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("No Trim", 10, -20);
        ofPopStyle();
        ofPopMatrix();
        
        tpNoTrimAnimation->draw(0, 180);
        
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
