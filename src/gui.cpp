//
//  gui.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 10/04/2017.
//
//

#include "gui.h"

void gui::setup(ScoreManager* _scoreManager, ofxOscSender* _sender) {
    scoreManager = _scoreManager;
    sender = _sender;
}

void gui::update() {
    
}

void gui::draw() {
    
}

void gui::resetGui() {
    // Create bundle variable
    ofxOscBundle b;
    
    // Create message to update player 1 score
    ofxOscMessage mSend1;
    mSend1.setAddress( "/1/label3" );
    string p1Score = "Player 1";
    mSend1.addStringArg( p1Score );
    b.addMessage( mSend1 );
    
    // Create message to update player 2 score
    ofxOscMessage mSend2;
    mSend2.setAddress( "/1/label2" );
    string p2Score = "Player 2";
    mSend2.addStringArg( p2Score );
    b.addMessage( mSend2 );
    
    // Send bundle
    sender->sendBundle( b );

    
    
}

bool gui::startGame() {
    
}
