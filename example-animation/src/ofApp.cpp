#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Lock to VSync
    ofSetVerticalSync(true);
    ofSetFrameRate(0);
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    sheet1.load("example.xml");
    sheet1.getAnimationNames();
    sheet1.getAnimatedSprite("1")->setSpeed(60);
    sheet1.getAnimatedSprite("1")->play();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    sheet1.getAnimatedSprite("1")->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    sheet1.getAnimatedSprite("1")->draw(ofGetWidth()/2 - sheet1.getAnimatedSprite("1")->getWidth()/2, ofGetHeight()/2 - sheet1.getAnimatedSprite("1")->getHeight()/2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1'){
         sheet1.getAnimatedSprite("1")->setSpeed(5);
    }else if(key == '2'){
         sheet1.getAnimatedSprite("1")->setSpeed(10);
    }else if(key == '3'){
         sheet1.getAnimatedSprite("1")->setSpeed(12);
    }else if(key == '4'){
         sheet1.getAnimatedSprite("1")->setSpeed(24);
    }else if(key == '5'){
         sheet1.getAnimatedSprite("1")->setSpeed(48);
    }else if(key == '6'){
        sheet1.getAnimatedSprite("1")->setSpeed(60);
    }else if(key == '7'){
        sheet1.getAnimatedSprite("1")->setSpeed(ofGetFrameRate());
    }
   
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
