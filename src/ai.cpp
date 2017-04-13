//
//  ai.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 07/04/2017.
//
//

#include "ai.h"

// Method to initialize the ai
void ai::setup(ScoreManager* _scoreManager, Paddle* _player2, Ball* _ball, class gui* _gui) {
    // Assign pointers
    scoreManager = _scoreManager;
    player2 = _player2;
    ball = _ball;
    gui = _gui;
    
    // Initialize a noise variable
    noise = ofRandom(1);
}

// Method to update the ai
void ai::update() {
    calcAction();
}

// Method to draw the ai
void ai::draw() {
    
}

// Method to calculate the next action
void ai::calcAction() {
    // Create a variable to hold the final action
    float action = 0;
    // Create a range around the ball within which the paddle will move around within
    float rangeSize = 0.75 * ofGetHeight();
    float rangeStart = ofGetHeight() - (ball->y - (rangeSize * 0.5));
    float rangeEnd = ofGetHeight() - (ball->y + (rangeSize * 0.5));
    // Noise function gets mapped to the window and sets the action's target within window
    action = ofMap(ofNoise(noise), 0, 1, rangeStart, rangeEnd);
    // Normalize action value
    action /= ofGetHeight();
    // Send the action to the action sender
    sendAction(action);
    // Increment the noise value
    noise += 0.03;
    // If the ai is holding the ball then it will release the ball at random
    if (ball->paddleBallSet && ball->x < 0.5 * ofGetWidth()) {
        if (ofRandom(180) > 179){
            ball->releasePaddle();
        }
    }
}

// Method to send an action
void ai::sendAction(float action) {
    // Only try to do this if the player object is assigned
    if (player2 != NULL) {
        // Send the action to the paddle
        player2->takeInput(action);
        // Send the action to update the gui
        gui->player2SliderPos(action);
    }
}
