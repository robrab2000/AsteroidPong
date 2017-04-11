//
//  ai.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 07/04/2017.
//
//

#include "ai.h"

void ai::setup(ScoreManager* _scoreManager, Paddle* _player2, Ball* _ball, class gui* _gui) {
    scoreManager = _scoreManager;
    player2 = _player2;
    ball = _ball;
    gui = _gui;
    
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
    // Create a range around the ball within which the paddle will move around within
    float rangeSize = 0.75 * winHeight;
    float rangeStart = winHeight - (ball->y - (rangeSize * 0.5));
    float rangeEnd = winHeight - (ball->y + (rangeSize * 0.5));
    // Noise function gets mapped to the window and sets the action's target within window
    action = ofMap(ofNoise(noise), 0, 1, rangeStart, rangeEnd);
    // Normalize action value
    action /= winHeight;
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

void ai::sendAction(float action) {
    if (player2 != NULL) {
        player2->takeInput(action);
        gui->player2SliderPos(action);
    }
}
