//
//  Ball.cpp
//  gravityPong
//
//  Created by Robert Homewood on 17/03/2017.
//
//

#include "Ball.h"
#include <algorithm>

// Define default constructor
Ball::Ball(){
}

// Method to initialize the ball
void Ball::setup(ScoreManager* _scoreManager, Paddle* _player1, Paddle* _player2, class
        gui* _gui, SoundManager* _soundManager){
    // Assign starting position
    x = ofGetWidth() * 0.5;
    y = ofGetHeight() * 0.5;
    
    // Define starting velocity
    startingX = 5;
    if(ofRandom(10) > 5) {
        startingX *= -1;
    }
    startingY = ofRandom(-3, 3);
    
    // Define the terminal velocity for the ball
    terminalX = 5;
    terminalY = 5;
    
    // Define the rate at which the ball slows towards the terminal speed
    speedDampen = 0.99;
    
    // Set starting speed
    speedX = startingX;
    speedY = startingY;
    
    // Define the width of the ball
    dim = 5;
    
    // Define a color for the ball
    color.set(255, 255, 255);
    
    // Assign pointers
    scoreManager = _scoreManager;
    player1 = _player1;
    player2 = _player2;
    gui = _gui;
    soundManager = _soundManager;
}

// Method to update the ball
void Ball::update(){
    // Call to dampen the ball speed
    dampenBallSpeed();
    // Check to see if a point has been scored
    checkForScore();
    // Check to see if ball is hitting a wall
    checkForWall();
    // Check to see if ball is hitting a paddle
    checkForPaddle();
    // Check if the ball is being held by a paddle
    if (paddleBallSet) {
        holdPaddleBall();
    }
    // Update the ball's position
    else {
        x+=speedX;
        y+=speedY;
    }
}

// Method to draw the ball
void Ball::draw(){
    // Set the ball's colour
    ofSetColor(color);
    ofPushMatrix();
        // Set the resolution of the ball circle
        ofSetCircleResolution(50);
        // Move the canvas to the ball's position
        ofTranslate(x, y);
        // Draw the actual ball
        ofDrawCircle(0, 0, dim);
    ofPopMatrix();
}

// Method to check for collision with the paddle
void Ball::checkForPaddle() {
    // If the ball is on the right hand side of the screen
    if(x > ofGetWidth() * 0.5) {
        // If the x position of the ball is less than it will move in the next frame
        if (ofDist(x, 0, player1->posX, 0) < speedX) {
            // If the y position lies within range of the paddle
            if ( y >= player1->posY && y <= player1->posY + player1->sizeY) {
                // Ball switched directions on X axis
                speedX *= -1;
                // Ball takes on some of the paddle's momentum on the y axis
                speedY += player1->velocityY * -0.5;
                // Ball preserves some of the paddle's momentum on the x axis too
//                speedX += (player1->velocityY * 0.5); // THIS NEEDS TUNING
                // Trigger pong sound
                soundManager->playPong(0.7);
            }
            
        }
    }
    // If the ball is on the left hand side of the screen
    if (x < ofGetWidth() * 0.5) {
        // If the x position of the ball is less than it will move in the next frame
        if (ofDist(x, 0, player2->posX + player2->sizeX, 0) < abs(speedX)) {
            // If the y position lies within range of the paddle
            if ( y >= player2->posY && y <= player2->posY + player2->sizeY) {
                // Ball switched directions on X axis
                speedX *= -1;
                // Ball takes on some of the paddle's momentum on the y axis
                speedY += player2->velocityY * -0.5;
                // Ball preserves some of the paddles velocity on the x axis too
//                speedX -= (player2->velocityY * 0.5); // THIS NEEDS TUNING
                // Trigger pong sound
                soundManager->playPong(-0.7);
            }

        }
    }
}

// Method to hold ball on the paddle
void Ball::holdPaddleBall() {
    // If the ball is being held by player 1
    if (ballPaddle == player1) {
        // Set the ball's position to follow the paddle
        x = ballPaddle->posX - dim * 1.5;
        y = ballPaddle->posY + (ballPaddle->sizeY * 0.5);
    }
    // If the ball is being held by player2
    else {
        // Set the ball's position to follow the paddle
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
        speedY = startingY * ofRandom(-1, 1);
        // Play ball release sound
        soundManager->ballRelease(0.7);
    }
    else {
        speedX = startingX;
        speedY = startingY * ofRandom(-1, 1);
        // Play ball release sound
        soundManager->ballRelease(-0.7);
    };
    // Tell the gui to stop showing the release button text
    gui->releaseBall();
}

// Method to check if the ball has left the area
void Ball::checkForScore() {
    
    if(x < 0 - dim){
        // increment player 1 score
        scoreManager->addScore(1, 10);
        speedX = 0;
        speedY= 0;
        ballPaddle = player2;
        paddleBallSet = true;
        soundManager->playPing(-0.75);
    } else if(x > ofGetWidth() + dim){
        // increment player 2 score
        scoreManager->addScore(2, 10);
        speedX = 0;
        speedY= 0;
        ballPaddle = player1;
        paddleBallSet = true;
        soundManager->playPing(0.75);
    }
}

// Method to check if the ball has hit a wall
void Ball::checkForWall() {
    // Check if the ball will collide with wall on the next frame
    if(y - speedY < 0 ){
        // Reverse the ball's movement
        y = 0 + dim;
        speedY *= -1;
        // Play audio for ball hitting the wall
        soundManager->playWall(x / ofGetWidth());
    }
    // Check if the ball will collide with wall on the next frame
    else if(y + speedY > ofGetHeight()){
        // Reverse the ball's movement
        y = ofGetHeight() - dim;
        speedY *= -1;
        // Play audio for ball hitting the wall
        soundManager->playWall(x / ofGetWidth());
    }
}

// Method to dampen the ball speed if its going too fast
void Ball::dampenBallSpeed() {
    // If the ball's absolute speed is greater than it's terminal velocity
    if (abs(speedX) > terminalX) {
        // Dampen the speed
        speedX *= speedDampen;
//        ofLog(OF_LOG_NOTICE, "X: " + ofToString(abs(speedX)));
    }
    // If the ball's absolute speed is greater than it's terminal velocity
    if (abs(speedY) > terminalY) {
        // Dampen the speed
        speedY *= speedDampen;
//        ofLog(OF_LOG_NOTICE, "Y: " + ofToString(abs(speedY)));
    }
}
