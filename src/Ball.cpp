//
//  Ball.cpp
//  gravityPong
//
//  Created by Robert Homewood on 17/03/2017.
//
//

#include "Ball.h"
#include <algorithm>

Ball::Ball(){
}

void Ball::setup(ScoreManager* _scoreManager, Paddle* _player1, Paddle* _player2, class gui* _gui){
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());
    
    startingX = 5;
    startingY = 5;
    
    speedX = startingX; //ofRandom(-5, 5);
    speedY = startingY; //ofRandom(-5, 5);
    
    dim = 5;
    
    noise= 1;
    
    color.set(255, 255, 255);
    
    scoreManager = _scoreManager;
    player1 = _player1;
    player2 = _player2;
    
    gui = _gui;
}

void Ball::update(){
    if(x < 0 - dim){
        // increment player 1 score
        scoreManager->addScore(1);
        speedX = 0;
        speedY= 0;
        ballPaddle = player2;
        paddleBallSet = true;
    } else if(x > ofGetWidth() + dim){
        // increment player 2 score
        scoreManager->addScore(2);
        speedX = 0;
        speedY= 0;
        ballPaddle = player1;
        paddleBallSet = true;
    }
    
    if(y < 0 ){
        y = 0 + dim;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight() - dim;
        speedY *= -1;
    }
    
    checkForPaddle();
    if (paddleBallSet) {
        holdPaddleBall();
    } else {
        x+=speedX;
        y+=speedY;
    }
}

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
    //ofDrawRectangle(x, y, dim, dim);
}

// Method to check for collision with the paddle
void Ball::checkForPaddle() {
    if(x > ofGetWidth() * 0.5) {
        if (ofDist(x, 0, player1->posX, 0) < speedX) {
            if ( y >= player1->posY && y <= player1->posY + player1->sizeY) {
                speedX *= -1;
                speedY += player1->velocityY * 0.5;
            }
            
        }
    }
    if (x < ofGetWidth() * 0.5) {
        if (ofDist(x, 0, player2->posX + player2->sizeX, 0) < abs(speedX)) {
            if ( y >= player2->posY && y <= player2->posY + player2->sizeY) {
                speedX *= -1;
                speedY += player2->velocityY * 0.5;
            }

        }
    }
}

// Method to hold ball on the paddle
void Ball::holdPaddleBall() {
    if (ballPaddle == player1) {
        x = ballPaddle->posX - dim * 1.5;
        y = ballPaddle->posY + (ballPaddle->sizeY * 0.5);
    }
    else {
        x = ballPaddle->posX + ballPaddle->sizeX + dim * 1.5;
        y = ballPaddle->posY + (ballPaddle->sizeY * 0.5);;
    }
    // Tell the gui to show the release button text
    gui->holdBall();
}

// Method to release the ball from the paddle
void Ball::releasePaddle() {
    if (paddleBallSet) {
        paddleBallSet = false;
    }
    if (ballPaddle == player1) {
        speedX = -startingX;
        speedY = startingY + ofRandom(-2, 2);
    }
    else {
        speedX = startingX;
        speedY = startingY + ofRandom(-2, 2);
    }
    // Tell the gui to stop showing the release button text
    gui->releaseBall();
}
