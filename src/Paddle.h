//
//  Paddle.h
//  gravityPong
//
//  Created by Robert Homewood on 17/03/2017.
//
//

#ifndef Paddle_h
#define Paddle_h

#include <stdio.h>
#include "ofMain.h"

class Paddle {
public:
    void setup(int, ofColor);
    void update();
    void draw();
    void calcPos();
    void checkBounds();
    void takeInput(float);
    
    int playerNumber;
    int posX, posY;
    int sizeX, sizeY;
    
    float terminalVelocity;
    float velocityY, accelerationY, targetY;
    
    ofColor myColor;
    
    Paddle();
    
    float posYLast;
    
};


#endif /* Paddle_h */
