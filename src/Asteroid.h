//
//  Asteroid.h
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//

#ifndef Asteroid_h
#define Asteroid_h

// Set the possible asteroid sizes
#define DIM1 5;
#define DIM2 10;
#define DIM3 20;
#define DIM4 40;

#include <stdio.h>
#include "ofMain.h"

class Asteroid {
public:
    void setup(ofVec2f, ofVec2f, int);
    void update();
    void draw();
    void setSize(int);
    void calcPos();
    void defineShape(float, float);
    
    ofVec2f position;
    ofVec2f velocity;
    float dim;
    float level;
    float rotator;
    float rotateRate;
    float resolution;
    
    float dim1, dim2, dim3;
    
    ofColor myColor;
    
    ofPath asteroidShape;
};

#endif /* Asteroid_h */
