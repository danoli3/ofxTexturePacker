#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    tpRotatedTrim = new ofxTexturePacker();
    tpRotatedTrim->load("texture/rotated-trim.xml");
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
    tpRotatedNoTrim = new ofxTexturePacker();
    tpRotatedNoTrim->load("texture/rotated-trim.xml");
    tpRotatedNoTrimAnimation = tpRotatedNoTrim->getAnimatedSprite("CapGuyWalk");
    if(tpRotatedNoTrimAnimation != NULL) {
        tpRotatedNoTrimAnimation->setSpeed(24);
        tpRotatedNoTrimAnimation->play();
    } else {
        ofLog(OF_LOG_FATAL_ERROR, "ofApp::setup():: Could not load animated sprite");
    }
    
    tpTrim = new ofxTexturePacker();
    tpTrim->load("texture/trim.xml");
    tpTrimAnimation = tpTrim->getAnimatedSprite("CapGuyWalk");
    if(tpTrimAnimation != NULL) {
        tpTrimAnimation->setSpeed(24);
        tpTrimAnimation->play();
    } else {
        ofLog(OF_LOG_FATAL_ERROR, "ofApp::setup():: Could not load animated sprite");
    }
    
    tpNoTrim = new ofxTexturePacker();
    tpNoTrim->load("texture/notrim.xml");
    tpNoTrimAnimation = tpNoTrim->getAnimatedSprite("CapGuyWalk");
    if(tpNoTrimAnimation != NULL) {
        tpNoTrimAnimation->setSpeed(24);
        tpNoTrimAnimation->play();
    } else {
        ofLog(OF_LOG_FATAL_ERROR, "ofApp::setup():: Could not load animated sprite");
    }
    
}

void ofApp::exit() {
    
    if(tpRotatedTrim) {
        delete tpRotatedTrim;
        tpRotatedTrim = NULL;
    }
    if(tpRotatedNoTrim) {
        delete tpRotatedNoTrim;
        tpRotatedNoTrim = NULL;
    }
    if(tpNoTrim) {
        delete tpNoTrim;
        tpNoTrim = NULL;
    }
    if(tpTrim) {
        delete tpTrim;
        tpTrim = NULL;
    }
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
        
        ofTranslate(10, 180);
        ofPushStyle();
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Rotation + Trim", 10, -20);
        ofPopStyle();
        tpRotatedTrimAnimation->draw(0,0);
        
        ofPopMatrix();
    }
    
    if(tpRotatedNoTrimAnimation){
        ofPushMatrix();
    
        ofTranslate(300, 180);
        ofPushStyle();
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Rotation + No Trim", 10, -20);
        ofPopStyle();
        tpRotatedNoTrimAnimation->draw(0,0);
        
        ofPopMatrix();
    }
    
    if(tpTrimAnimation){
        ofPushMatrix();
        
        ofTranslate(300*2, 180);
        ofPushStyle();
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Trim", 10, -20);
        ofPopStyle();
        tpTrimAnimation->draw(0,0);
        
        ofPopMatrix();
    }
    
    if(tpNoTrimAnimation){
        ofPushMatrix();
        
        ofTranslate(300*3, 180);
        ofPushStyle();
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("No Trim", 10, -20);
        ofPopStyle();
        tpNoTrimAnimation->draw(0,0);
        
        ofPopMatrix();
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
