//
//  Paddle.cpp
//  gravityPong
//
//  Created by Robert Homewood on 17/03/2017.
//
//

#include "Paddle.h"

// Default constructor
Paddle::Paddle() {
}

// Method to initialize the Paddle
void Paddle::setup(int _playerNumber, ofColor _myColor) {
    // Assign a colour for the paddle
    myColor = _myColor;
    
    // Assign player number
    playerNumber = _playerNumber;
    
    // Define the size that the paddle
    sizeX = 20;
    sizeY = 100;
    
    // Define starting velocity
    velocityY = 0;
    
    // Set starting Y position to half way up screen
    posY = (ofGetHeight() * 0.5) + sizeY * 0.5;
    
    // Define which player number this is and position it accordingly
    setPositionX();
}

// Method to update the paddle
void Paddle::update() {
    // Calculate the current position
    calcPos();
    // Check that the paddle is within screen bounds
    checkBounds();
}

// Method to draw the paddle
void Paddle::draw() {
    ofPushMatrix();
        // Set the colour
        ofSetColor(myColor);
        // Draw the actual paddle at location
        ofTranslate(posX, posY);
        ofDrawRectangle(0, 0, sizeX, sizeY);
    ofPopMatrix();
}

// Method to calculate the current position
void Paddle::calcPos() {
    // Record the position at the last frame
    posYLast = posY;
    // Lero towards the target over the frame
    posY = ofLerp(posY, targetY, ofGetLastFrameTime() * 10);
    // Dampen the movement
    velocityY = posYLast -posY;
    // Recalculate X position in case of window resize
    setPositionX();
    
}

// Check that the paddle is within the screen bounds
void Paddle::checkBounds() {
    if (posY > ofGetHeight() - sizeY) {
        velocityY = 0;
        accelerationY = 0;
        posY = ofGetHeight() - sizeY;
    }
    if (posY < 0) {
        velocityY = 0;
        accelerationY = 0;
        posY = 0;
    }
}

// Method to accept a new input target position
void Paddle::takeInput(float newInput) {
    targetY = ofMap(ofClamp(newInput, 0.1, 0.9), 0.1, 0.9, ofGetHeight() - sizeY, 0);
}

// Method to set the X position
void Paddle::setPositionX() {
    // Define which player number this is and position it accordingly
    if (playerNumber == 1) {
        posX = ofGetWidth() - (sizeX * 3);
    }
    else if (playerNumber == 2) {
        posX = sizeX * 2;
    }
}
