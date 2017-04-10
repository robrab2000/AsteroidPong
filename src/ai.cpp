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
    maxStepSize = 0.5;
    winHeight = ofGetHeight();
}

void ai::update() {
    calcAction();
}

void ai::draw() {
    
}

void ai::calcAction() {
    // Create a variable to hold the final action
    float action = 0;
    // Take note of the ball's Y position
    float ballY = ball->y;
    // Take note of the player's current position
    float playerY = player2->posY;
    
    // Create a window around the ball within which the paddle will attempt to move around within
    float window = 0.75 * winHeight;
    float windowStart = winHeight - (ballY - (window * 0.5));
    float windowEnd = winHeight - (ballY + (window * 0.5));
    // Noise function gets mapped to the window and sets the action's target within window
    float actionTarget = ofMap(ofNoise(noise), 0, 1, windowStart, windowEnd);
    // if the target position is greater than the player's current position then set the action target position as the player's current position increased by the step value and vice versa
    if (actionTarget > playerY) {
        action = playerY + (maxStepSize);// * ofNoise(noise));
    }
    else if (actionTarget < playerY) {
        action = playerY - (maxStepSize);// * ofNoise(noise));
    }
    // Normalize action value again
    actionTarget /= winHeight;                      // TEMP, SHOULD BE ACTION
    // Send the action to the action sender
    sendAction(actionTarget);                       // TEMP, SHOULD BE ACTION
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
