//
//  gui.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 10/04/2017.
//
//

#include "gui.h"

// Method to initialize the gui
void gui::setup(ScoreManager* _scoreManager, ofxOscSender* _sender) {
    // Assign pointers
    scoreManager = _scoreManager;
    sender = _sender;
}

// Method to update the gui
void gui::update() {
    
}

// Method to draw the gui
void gui::draw() {
    
}

// Method to reset the gui
void gui::resetGui() {
    // Create bundle variable
    ofxOscBundle b;
    
    // Create message to reset player 1 score
    ofxOscMessage mSend1;
    mSend1.setAddress( "/1/label3" );
    string p1Score = "Player 1";
    mSend1.addStringArg( p1Score );
    b.addMessage( mSend1 );
    
    // Create message to reset player 2 score
    ofxOscMessage mSend2;
    mSend2.setAddress( "/1/label2" );
    string p2Score = "Player 2";
    mSend2.addStringArg( p2Score );
    b.addMessage( mSend2 );
    
    // Create message to reset release button
    ofxOscMessage mSend3;
    mSend3.setAddress("/1/Release");
    string release = " ";
    mSend3.addStringArg(release);
    b.addMessage(mSend3);
    
    // Send bundle
    sender->sendBundle( b );
    
    // Reset the slider positions
    player1SliderPos(0.5);
    player2SliderPos(0.5);
}

// Method to tell TouchOSC that the ball is being held
void gui::holdBall() {
    ofxOscMessage m;
    m.setAddress( "/1/Release" );
    m.addStringArg(  "Release!" );
    sender->sendMessage( m );
}

// Method to tell TouchOSC that the ball has been released
void gui::releaseBall() {
    ofxOscMessage m;
    m.setAddress( "/1/Release" );
    m.addStringArg(  " " );
    sender->sendMessage( m );
}

// Method to update the slider for player 1
void gui::player1SliderPos(float newPos) {
    // Package and send the new position for player 1 slider
    ofxOscMessage m;
    m.setAddress( "/1/fader7" );
    m.addFloatArg( newPos );
    sender->sendMessage( m );
}

// Method to update the slider for player 2
void gui::player2SliderPos(float newPos) {
    // Package and send the new position for player 2 slider
    ofxOscMessage m;
    m.setAddress( "/1/fader8" );
    m.addFloatArg( newPos );
    sender->sendMessage( m );
}
