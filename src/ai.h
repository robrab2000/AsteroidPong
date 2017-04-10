//
//  ai.h
//  effingRidiculousPong
//
//  Created by Robert Homewood on 07/04/2017.
//
//

#ifndef ai_h
#define ai_h

#include <stdio.h>
#include "ofMain.h"
#include "ScoreManager.h"
#include "Paddle.h"
#include "Ball.h"
#include "ofxOsc.h"

class ai {
    
public:
    void setup(ScoreManager*, Paddle*, Ball*, ofxOscSender*);
    void update();
    void draw();
    void calcAction();
    void sendAction(float);
    void sendOscMessage(float);
    
    
    float noise;
    float maxStepSize;
    float winHeight;
    
    ScoreManager* scoreManager;
    
    Paddle* player2;

    Ball* ball;
    
    ofxOscSender* sender;
};


#endif /* ai_h */
