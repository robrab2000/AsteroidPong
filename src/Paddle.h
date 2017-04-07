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
    void calcGravity();
    void jump();
    void calcPos();
    void checkBounds();
    void takeInput(float);
    
    int playerNumber;
    int posX, posY;
    int sizeX, sizeY;
    
    float gravityForce, jumpForce, terminalVelocity;
    float velocityY, accelerationY;
    
    ofColor myColor;
    
    Paddle();
    
};


#endif /* Paddle_h */
