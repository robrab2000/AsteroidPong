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
#include "ofxOsc.h"
class Ball {
    
public:
    void setup(ScoreManager*, Paddle*, Paddle*, ofxOscSender*);
    void update();
    void draw();
    void collideBall(); //float argument for
    void checkForPaddle();
    void holdPaddleBall();
    void releasePaddle();
    
    // variables
    float startingX;
    float startingY;
    float x;
    float y;
    float speedY;
    float speedX;
    float noise;
    float paddlePos;
    int dim;
    ofColor color;
    bool paddleBallSet;
    
    
    
    Ball();
    
    ScoreManager* scoreManager;
    ofxOscSender* sender;
    
    Paddle* player1;
    Paddle* player2;
    Paddle* ballPaddle;
    
private:
    
    
}; 
#endif /* Ball_h */
