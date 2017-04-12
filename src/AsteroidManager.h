//
//  AsteroidManager.h
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//

#ifndef AsteroidManager_h
#define AsteroidManager_h

#include <stdio.h>
#include "ofMain.h"
#include "Asteroid.h"
#include "Paddle.h"

class AsteroidManager {
public:
    void setup(Paddle*, Paddle*);
    void update();
    void draw();
    void createAsteroid(ofVec2f, ofVec2f, int);
    ofVec2f randomAsteroidPosition();
    
    ofVec2f vec;
    
    Paddle* player1;
    Paddle* player2;
    
    vector<Asteroid> Asteroids;
    
};

#endif /* AsteroidManager_h */
