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
#define DIM1 7;
#define DIM2 15;
#define DIM3 25;

#include <stdio.h>
#include "ofMain.h"

class Asteroid {
public:
    void setup(ofVec2f, ofVec2f, int);
    void update();
    void draw();
    void setSize(int);
    void calcPos();
    
    ofVec2f position;
    ofVec2f velocity;
    float dim;
    float level;
    float rotator;
    float rotateRate;
    
    float dim1, dim2, dim3;
    
    ofColor myColor;
};

#endif /* Asteroid_h */
