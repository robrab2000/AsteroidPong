//
//  ai.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 07/04/2017.
//
//

#include "ai.h"

void ai::setup(ScoreManager* _scoreManager, Paddle* _player2, Ball* _ball, ofxOscSender* _sender) {
    scoreManager = _scoreManager;
    player2 = _player2;
    ball = _ball;
    sender = _sender;
    
    noise = ofRandom(1);
    maxStepSize = 5;
    
}

void ai::update() {
    calcAction();
}

void ai::draw() {
    
}

void ai::calcAction() {
    // Create a variable to hold the final action
    float action = 0;
    // Create a window around the ball within which the paddle will attempt to move around within
    float window = 0.75 * ofGetHeight();
    float windowStart = (ofGetHeight() - (ball->y - (window * 0.5))) / ofGetHeight();
    float windowEnd = (ofGetHeight() - (ball->y + (window * 0.5))) / ofGetHeight();
    // Noise function gets mapped to the window and sets the action's target within window
    float actionTarget = ofMap(ofNoise(noise), 0, 1, windowStart, windowEnd);
    // Take note of the player's current position
    float playerY = player2->posY;
    
    // 'UnNormalize' the actionTarget value (see: http://bit.ly/2nVVfs4 for a bit of a chortle)
    actionTarget *= ofGetHeight();
    // if the target position is greater than the player's current position then set the action' position as the player's current position increased by the step value and vice versa
    if (actionTarget > playerY) {
        action = playerY + (maxStepSize);// * ofNoise(noise));
    }
    else if (actionTarget < playerY) {
        action = playerY - (maxStepSize);// * ofNoise(noise));
    }
    // Normalize action value again
    action /= ofGetHeight();
    // Send the action to the action sender
    sendAction(action);
    // Increment the noise value
    noise += 0.03;
}

void ai::sendAction(float action) {
    if (player2 != NULL) {
        player2->takeInput(action);
        sendOscMessage(action);
    }
}

void ai::sendOscMessage(float action) {
    ofxOscMessage m;
    m.setAddress( "/1/fader8" );
    m.addFloatArg( action );
    sender->sendMessage( m );
}
