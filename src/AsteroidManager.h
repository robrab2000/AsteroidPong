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
#include "Ball.h"
#include "SoundManager.h"

class AsteroidManager {
public:
    void setup(Paddle*, Paddle*, Ball*, SoundManager*);
    void update();
    void draw();
    void createAsteroid(ofVec2f, ofVec2f, int);
    ofVec2f randomAsteroidPosition();
    void checkForCollisions();
    void checkForBallCollision(Asteroid, int);
    void checkForAsteroidCollision(Asteroid*, int);
    void checkForPaddleCollision(Asteroid*);
    void checkForWallCollision(Asteroid*, int);
    
    
    ofVec2f vec;
    
    Paddle* player1;
    Paddle* player2;
    
    Ball* ball;
    
    vector<Asteroid> Asteroids;
    
    SoundManager* soundManager;
    
};

#endif /* AsteroidManager_h */
