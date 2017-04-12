//
//  Asteroid.h
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//

#ifndef Asteroid_h
#define Asteroid_h

#include <stdio.h>
#include "ofMain.h"

class Asteroid {
public:
    void setup(ofVec2f, ofVec2f, int);
    void update();
    void draw();
    void setSize(int);
    
    ofVec2f position;
    ofVec2f velocity;
    float dim;
    float level;
    
    
    float dim1, dim2, dim3;
};

#endif /* Asteroid_h */
