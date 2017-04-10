#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gameStarted = false;
    scoreManager.setup();
    ofBackground(0, 0, 0);
    player1.setup(1, ofColor(255));
    player2.setup(2, ofColor(255));
    ball.setup(&scoreManager, &player1, &player2);
    ofSetBackgroundAuto(true);
    // listen on the given port
    cout << "listening for osc messages on port " << RECEIVER_PORT << "\n";
    receiver.setup(RECEIVER_PORT);
    
    // send on the given port
    cout << "sending osc messages on port " << SENDER_PORT << " and ip " << SENDER_IP << "\n";
    sender.setup(SENDER_IP, SENDER_PORT);
    aiPlayer.setup(&scoreManager, &player2, &ball, &sender);
    
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (gameStarted) {
        ball.update();
        if (!twoPlayers) {
            aiPlayer.update();
        }
        player1.update();
        player2.update();
        checkOSC();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    drawNet();

    ball.draw();
    
    if (gameStarted) {
        scoreManager.draw();
    }
    
    player1.draw();
    
    player2.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        twoPlayers = false;
        gameStarted = true;
    }
    
    if (key == '2') {
        twoPlayers = true;
        gameStarted = true;
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

//--------------------------------------------------------------
void ofApp::checkOSC() {
    if (messageBuffer.size()>maxBufferSize) messageBuffer.pop_back();
    
    // check for waiting messages
    while (receiver.hasWaitingMessages()) {
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
//       ofLog(OF_LOG_NOTICE, ofToString(m.getArgAsFloat(0)));
        
        if (m.getAddress() == "/1/fader7") {
            player1.takeInput(m.getArgAsFloat(0));
        }
        if (m.getAddress() == "/1/fader8") {
            if(twoPlayers) {
                player2.takeInput(m.getArgAsFloat(0));
            }
        }
    }
}
//--------------------------------------------------------------
void ofApp::startGame() {
    gameStarted = true;
}
