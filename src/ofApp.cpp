#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    scoreManager.setup();
    ofBackground(0, 0, 0);
    player1.setup(1, ofColor(255));
    player2.setup(2, ofColor(255));
    ball.setup(&scoreManager, &player1, &player2);
    ofSetBackgroundAuto(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    ball.update();
    player1.update();
    player2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    drawNet();

    ball.draw();
    
    scoreManager.draw();
    
    player1.draw();
    
    player2.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        player1.jump();
    }
    
    if (key == '2') {
        player2.jump();
    }
    if (key == '3') {
        ball.releasePaddle();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
//--------------------------------------------------------------
void ofApp::drawNet(){
    int netPieces = 20;
    float netWidth = 10;
    for (int i = 0; i < netPieces; i++) {
        ofPushMatrix();
        ofTranslate((ofGetWidth() * 0.5) - (netWidth * 0.5), i * ofGetHeight() / (float)netPieces);
        ofDrawRectangle(0, 0, netWidth, ofGetHeight() / (float)netPieces / 2);
        ofPopMatrix();
    }
}
