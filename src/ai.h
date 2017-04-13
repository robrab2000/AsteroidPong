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
#include "gui.h"

class ai {
    
public:
    void setup(ScoreManager*, Paddle*, Ball*, gui*);
    void update();
    void draw();
    void calcAction();
    void sendAction(float);
    void sendOscMessage(float);
    
    
    float noise;
    
    ScoreManager* scoreManager;
    
    Paddle* player2;

    Ball* ball;
    
    ofxOscSender* sender;
    
    gui* gui;
};


#endif /* ai_h */
