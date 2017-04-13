#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Set the game to not yet started
    gameStarted = false;
    // Set the background
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(true);
    // Set the gam's framerate
    ofSetFrameRate(60);
    
    // Initialize the scoreManager
    scoreManager.setup();
    // Initialize the two players
    player1.setup(1, ofColor(255));
    player2.setup(2, ofColor(255));
    // Initialize the ball
    ball.setup(&scoreManager, &player1, &player2, &gui, &soundManager);
    
    // Initialize OSC
        // listen on the given port
        cout << "listening for osc messages on port " << RECEIVER_PORT << "\n";
    receiver.setup(RECEIVER_PORT);
    
        // send on the given port
        cout << "sending osc messages on port " << SENDER_PORT << " and ip " << SENDER_IP << "\n";
    sender.setup(SENDER_IP, SENDER_PORT);
    // Initialize AI
    aiPlayer.setup(&scoreManager, &player2, &ball, &gui);
    // Initialize GUI
    gui.setup(&scoreManager, &sender);
    gui.resetGui();
    // Initialize sound
    soundManager.setup(true);
    // Initialize the asteroid Manager
    asteroidManager.setup(&player1, &player2, &ball, &soundManager, &scoreManager);
}

//--------------------------------------------------------------
void ofApp::update(){
    // Checks for OSC input
    checkOSC();
    // If the game has started
    if (gameStarted) {
        // Update the ball
        ball.update();
        // If there is only one player
        if (!twoPlayers) {
            // Update the AI
            aiPlayer.update();
        }
        // Update the 1st player
        player1.update();
        // Update the 2nd player
        player2.update();
        // Update the asteroid Manager
        asteroidManager.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw the net
    drawNet();
    // Draw the ball
    ball.draw();
    // Draw the asteroids
    asteroidManager.draw();
    // Draw the 1st player
    player1.draw();
    // Draw the 2nd player
    player2.draw();
    // Draw the score manager
    scoreManager.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // These are just for debuggin purposes
    
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
    // Define the properties of the net
    int netPieces = 20;
    float netWidth = 10;
    // Iterate through the pieces of net
    for (int i = 0; i < netPieces; i++) {
        ofPushMatrix();
        // Move the canvas to draw the next piece
        ofTranslate((ofGetWidth() * 0.5) - (netWidth * 0.5), i * ofGetHeight() / (float)netPieces);
        // Draw this piece of the net
        ofDrawRectangle(0, 0, netWidth, ofGetHeight() / (float)netPieces / 2);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::exit() {
    // Resets the gui upon exiting the game
    gui.resetGui();
}

//--------------------------------------------------------------
void ofApp::checkOSC() {
    // Send incoming osc messages into the buffer
    if (messageBuffer.size()>maxBufferSize) messageBuffer.pop_back();
    
    // Check for waiting messages
    while (receiver.hasWaitingMessages()) {
        // Get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        // If the message is from player 1's fader
        if (m.getAddress() == "/1/fader7") {
            player1.takeInput(m.getArgAsFloat(0));
            if (!gameStarted) {
                twoPlayers = false;
                gameStarted = true;
            }
        }
        // If the message is from player 1's fader
        if (m.getAddress() == "/1/fader8") {
            if(!gameStarted){
                twoPlayers = true;
                gameStarted = true;
            }
            if(twoPlayers) {
                player2.takeInput(m.getArgAsFloat(0));
            }
        }
        // If the message is from the release button
        if (ball.ballPaddle != NULL) {
            if (twoPlayers == true || ball.ballPaddle->playerNumber == 1 ) {
                if (ball.paddleBallSet) {
                    if (m.getAddress() == "/1/push1") {
                        ball.releasePaddle();
                    }
                }
            }
        }
    }
    
    // If the game has started
    if (gameStarted) {
        // Create bundle variable
        ofxOscBundle b;
        
        // Create message to update player 1 score
        ofxOscMessage mSend1;
        mSend1.setAddress( "/1/label3" );
        string p1Score = "Score: " + ofToString(scoreManager.player1Score);
        mSend1.addStringArg( p1Score );
        b.addMessage( mSend1 );
        
        // Create message to update player 2 score
        ofxOscMessage mSend2;
        mSend2.setAddress( "/1/label2" );
        string p2Score = "Score: " + ofToString(scoreManager.player2Score);
        mSend2.addStringArg( p2Score );
        b.addMessage( mSend2 );
        
        // Send bundle
        sender.sendBundle( b );
    }

}
//--------------------------------------------------------------
void ofApp::startGame() {
    // Start the game
    gameStarted = true;
}
