//
//  Paddle.cpp
//  gravityPong
//
//  Created by Robert Homewood on 17/03/2017.
//
//

#include "Paddle.h"
#define SMOOTHSTEP(x) ((x) * (x) * (3 - 2 * (x)))

Paddle::Paddle() {
}

void Paddle::setup(int _playerNumber, ofColor _myColor) {
    
    sizeX = 20;
    sizeY = 100;
    
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
//    calcGravity();
    calcPos();
    checkBounds();
}

void Paddle::draw() {
    ofPushMatrix();
    ofSetColor(myColor);
    ofDrawRectangle(posX, posY, sizeX, sizeY);
    ofPopMatrix();
}

void Paddle::calcPos() {
//    accelerationY = (targetY - posY ) * 0.01;
//    velocityY += accelerationY;
//    posY += ofClamp(velocityY, -terminalVelocity, terminalVelocity);
//    if (abs(posY - targetY) <= 10) {
//        velocityY *= 0.5;
//        accelerationY *= 0.5;
//    }

    posY = ofLerp(posY, targetY, ofGetLastFrameTime() * 10);
    //SMOOTHSTEP(posY);
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

void Paddle::takeInput(float newInput) {
    targetY = ofMap(ofClamp(newInput, 0.1, 0.9), 0.1, 0.9, ofGetHeight() - sizeY, 0);
}
