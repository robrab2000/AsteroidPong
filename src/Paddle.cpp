//
//  Paddle.cpp
//  gravityPong
//
//  Created by Robert Homewood on 17/03/2017.
//
//

#include "Paddle.h"

Paddle::Paddle() {
}

void Paddle::setup(int _playerNumber, ofColor _myColor) {
    
    sizeX = 20;
    sizeY = 100;
    
    gravityForce = 0.05;
    jumpForce = -12.5;
    
    velocityY = 0;
    terminalVelocity = 20;
    
    myColor = _myColor;
    
    playerNumber = _playerNumber;
    if (playerNumber == 1) {
        posX = ofGetWidth() - (sizeX * 3);
    }
    else if (playerNumber == 2) {
        posX = sizeX * 2;
    }
    posY = (ofGetHeight() * 0.5) + sizeY * 0.5;
}

void Paddle::update() {
    calcGravity();
    calcPos();
    checkBounds();
}

void Paddle::draw() {
    ofPushMatrix();
    ofSetColor(myColor);
    ofDrawRectangle(posX, posY, sizeX, sizeY);
    ofPopMatrix();
}

void Paddle::calcGravity() {
    if (posY < ofGetHeight() - sizeY) {
        accelerationY += gravityForce;
    }
}

void Paddle::jump() {
    accelerationY = 0;
    velocityY = jumpForce;
}

void Paddle::calcPos() {
    velocityY += accelerationY;
    posY += ofClamp(velocityY, -terminalVelocity, terminalVelocity);
    
}

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
