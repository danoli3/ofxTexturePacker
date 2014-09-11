#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    texturePacker.load("texture/spritesheet.xml");
    tp.loadImage("tp.png");
    small.loadImage("texture/small.png");
    sprite = texturePacker.getSprite("Box2.png");
    animatedSprite = texturePacker.getAnimatedSprite("CapGuyWalk");
    if(animatedSprite == NULL) {
        return;
    }
    animatedSprite->setSpeed(24);
    animatedSprite->play();
    
    bg.loadImage("texture/bg.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    animatedSprite->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // -------- Draws the ofxTexturePacker logo gif
    bg.draw(0,0);
    ofSetColor(255, 255, 0);
    
    ofSetColor(255,255,255);
    ofPushMatrix();
    ofTranslate(400, 0);
    ofScale(0.25, 0.25);
    tp.draw(0,0, tp.width, tp.height);
    ofPopMatrix();
    ofPushMatrix();
    ofScale(0.25, 0.25);
    animatedSprite->draw(1300,35);
    ofPopMatrix();
    
    
    //---------- Else Draw the sprites:
    sprite->draw(50,0);
    
    animatedSprite->draw(300,300);


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
