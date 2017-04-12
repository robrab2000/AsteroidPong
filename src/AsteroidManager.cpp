//
//  AsteroidManager.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//

#include "AsteroidManager.h"
// Method to initialize the asteroids
void AsteroidManager::setup(Paddle* _player1, Paddle* _player2, Ball* _ball) {
    // Assign the player objects
    player1 = _player1;
    player2 = _player2;
    // Assign the ball object
    ball = _ball;
    
    for (int i = 0; i < 10; i++) {
        createAsteroid(randomAsteroidPosition(), ofVec2f(0,0), 3);
    }
}

// Method to update the asteroids
void AsteroidManager::update() {
    // Loop through the asteroids and update them
    for (int i = 0; i < Asteroids.size(); i++) {
        Asteroids[i].update();
    }
    // Call the collision detection for the asteroids
    checkForCollisions();
}

// Method to draw the asteroids
void AsteroidManager::draw() {
    // Loop through the asteroids and draw them
    for (int i = 0; i < Asteroids.size(); i++) {
        Asteroids[i].draw();
    }
}

// Method to create a new asteroid with specific properties
void AsteroidManager::createAsteroid(ofVec2f _position, ofVec2f _velocity, int _level) {
    // Create the new asteroid
    Asteroid newAsteroid;
    // Initialize the new asteroid
    newAsteroid.setup(_position, _velocity, _level);
    // Push the new asteroid onto the vector
    Asteroids.push_back(newAsteroid);
}

// Method to determine a valid position for a new asteroid
ofVec2f AsteroidManager::randomAsteroidPosition() {
    bool isOkay = false;
    ofVec2f newPoint;
    
    while(!isOkay) {
        newPoint = ofVec2f(ofRandom(player2->posX + player2->sizeX + 30, player1->posX - 30), ofRandom(30, ofGetHeight() - 30));
        // If the vector of asteroids is empty then just accept the position
        if (Asteroids.size() == 0) {
            isOkay = true;
        }
        // If there are asteroids already, check that the new asteroids is not too close
        for (int i = 0; i < Asteroids.size(); i++) {
            if (ofDist(newPoint.x, newPoint.y, Asteroids[i].position.x, Asteroids[i].position.y) > 30) {
                isOkay = true;
            }
        }
    }
    // Return the new position
    return newPoint;
}

void AsteroidManager::checkForCollisions() {
    for (int i = 0; i < Asteroids.size(); i++) {
        if (ofDist(Asteroids[i].position.x, Asteroids[i].position.y, ball->x, ball->y) < Asteroids[i].dim + ball->dim) {
            //Asteroids[i].myColor = ofColor(0,0,0);
            Asteroids.erase(Asteroids.begin() + i);
            ofLog(OF_LOG_NOTICE, "DESTROY!! ");
        }
    }
}
