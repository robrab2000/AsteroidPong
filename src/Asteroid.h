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
    void setup(float, float, int);
    void update();
    void draw();
    void setSize(int);
    
    float posX;
    float posY;
    float dim;
    float level;
};

#endif /* Asteroid_h */
