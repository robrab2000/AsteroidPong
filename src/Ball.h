//
//  Ball.h
//  gravityPong
//
//  Created by Robert Homewood on 17/03/2017.
//
//

#ifndef Ball_h
#define Ball_h

#include <stdio.h>
#include "ofMain.h"
#include "ScoreManager.h"
#include "Paddle.h"
#include "gui.h"
#include "SoundManager.h"

class Ball {
    
public:
    void setup(ScoreManager*, Paddle*, Paddle*, gui*, SoundManager*);
    void update();
    void draw();
    void checkForPaddle();
    void holdPaddleBall();
    void releasePaddle();
    void checkForScore();
    void checkForWall();
    void dampenBallSpeed();
    
    // variables
    float startingX;
    float startingY;
    float x;
    float y;
    float speedY;
    float speedX;
    float noise;
    float paddlePos;
    float speedDampen;
    float terminalX;
    float terminalY;
    int dim;
    ofColor color;
    bool paddleBallSet;
    
    
    
    Ball();
    
    ScoreManager* scoreManager;
    gui* gui;
    
    Paddle* player1;
    Paddle* player2;
    Paddle* ballPaddle;
    
    SoundManager* soundManager;
    
private:
    
    
}; 
#endif /* Ball_h */
