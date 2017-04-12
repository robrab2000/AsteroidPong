//
//  AsteroidManager.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//

#include "AsteroidManager.h"
// Method to initialize the asteroids
void AsteroidManager::setup(Paddle* _player1, Paddle* _player2, Ball* _ball, SoundManager* _soundManager) {
    // Assign the player objects
    player1 = _player1;
    player2 = _player2;
    // Assign the ball object
    ball = _ball;
    // Assign the soundmanager
    soundManager = _soundManager;
    
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

// Method to check for all kinds of collision
void AsteroidManager::checkForCollisions() {
    // Loop through all of the asteroids
    for (int i = 0; i < Asteroids.size(); i++) {
        checkForBallCollision(Asteroids[i], i);
//        checkForAsteroidCollision(&Asteroids[i], i);
        checkForPaddleCollision(&Asteroids[i]);
        checkForWallCollision(&Asteroids[i], i);
    }
}

// Method to check for collisions with the ball
void AsteroidManager::checkForBallCollision(Asteroid asteroid, int index) {
    // Make sure the ball is not currently being held or the game will crash!
    if (!ball->paddleBallSet) {
        // Check whether the asteroid is too close to a ball
        if (ofDist(asteroid.position.x, asteroid.position.y, ball->x, ball->y) < asteroid.dim + ball->dim) {
            // If the asteroid has a level above 1
            if (asteroid.level > 1) {
                // Create new smaller Asteroids
                for (int j = 0; j < asteroid.level -1; j++) {
                    // Set the velocity of the new asteroid
                    ofVec2f newVel = ofVec2f(ball->speedX * ofRandom(1.0, 1.5), ball->speedY + ofRandom(-3, 3));
                    // Set the new position of the new asteroid
                    ofVec2f newPos = asteroid.position + newVel;
                    // Create the new asteroid
                    createAsteroid(newPos, newVel, asteroid.level - 1);
                }
            }
            // Make sound for asteroid exploding
            soundManager->playExplosion(asteroid.position.x / ofGetWidth());
            // Destroy the asteroid
            Asteroids.erase(Asteroids.begin() + index);
        }
    }
}

// Method to check for collisions between asteroids
void AsteroidManager::checkForAsteroidCollision(Asteroid* asteroid, int index) {
    
    // Loop through all of the asteroids
    for (int i = 0; i < Asteroids.size(); i++) {
        float smallerAsteroid;
        if (asteroid->dim < Asteroids[i].dim) {
            smallerAsteroid = asteroid->dim;
        } else {
            smallerAsteroid = Asteroids[i].dim;
        }
        if (ofDist(asteroid->position.x, asteroid->position.y, Asteroids[i].position.x, Asteroids[i].position.y) < smallerAsteroid) {
            // If the asteroid has a level above 1
            if (asteroid->level > 1) {
                // Create new smaller Asteroids
                for (int j = 0; j < asteroid->level -1; j++) {
                    // Set the velocity of the new asteroid
                    ofVec2f newVel = ofVec2f(Asteroids[i].velocity.x * ofRandom(1.0, 1.5), Asteroids[i].velocity.y);
                    // Set the new position of the new asteroid
                    ofVec2f newPos = asteroid->position + newVel;
                    // Create the new asteroid
                    createAsteroid(newPos, newVel, asteroid->level - 1);
                }
            }
            // Destroy the asteroid
            Asteroids.erase(Asteroids.begin() + index);
        }
    }
}

// Method to check for collisions with paddle
void AsteroidManager::checkForPaddleCollision(Asteroid* asteroid) {
    
    if(asteroid->position.x > ofGetWidth() * 0.5) {
        if (ofDist(asteroid->position.x, 0, player1->posX, 0) < asteroid->velocity.x) {
            if ( asteroid->position.y >= player1->posY && asteroid->position.y <= player1->posY + player1->sizeY) {
                // Ball switched directions on X axis and Ball takes on some of the paddle's momentum on the y axis
                asteroid->velocity = ofVec2f(asteroid->velocity.x * -1, asteroid->velocity.y += player1->velocityY * -0.5);
                // Ball preserves some of the paddle's momentum on the x axis too
                asteroid->velocity.x + (player1->velocityY * 1);
                // Trigger pong sound
                soundManager->playPong(0.7);
            }
            
        }
    }
    
    if (asteroid->position.x < ofGetWidth() * 0.5) {
        if (ofDist(asteroid->position.x, 0, player2->posX + player2->sizeX, 0) < abs(asteroid->velocity.x)) {
            if ( asteroid->position.y >= player2->posY && asteroid->position.y <= player2->posY + player2->sizeY) {
                // Ball switched directions on X axis and Ball takes on some of the paddle's momentum on the y axis
                asteroid->velocity = ofVec2f(asteroid->velocity.x *= -1, asteroid->velocity.y += player2->velocityY * -0.5);
                // Ball preserves some of the paddles velocity on the x axis too
                asteroid->velocity.x - (player2->velocityY * 1);
                // Trigger pong sound
                soundManager->playPong(-0.7);
            }
            
        }
    }

}

// Method to check for collisions with wall
void AsteroidManager::checkForWallCollision(Asteroid* asteroid, int index) {
    if(asteroid->position.y < 0 ){
        asteroid->position.y = 0 + ball->dim;
        asteroid->velocity = ofVec2f(asteroid->velocity.x, asteroid->velocity.y * -1);
        soundManager->playWall(asteroid->position.x / ofGetWidth());
    } else if(asteroid->position.y > ofGetHeight()){
        asteroid->position.y = ofGetHeight() - ball->dim;
        asteroid->velocity = ofVec2f(asteroid->velocity.x, asteroid->velocity.y * -1);
        soundManager->playWall(asteroid->position.x / ofGetWidth());
    }
    
    // Check if asteroid has gone off map and destroy
    if (asteroid->position.x < 0 - asteroid->dim) {
        // Destroy the asteroid
        Asteroids.erase(Asteroids.begin() + index);
    }
    if (asteroid->position.x > ofGetWidth() + asteroid->dim) {
        // Destroy the asteroid
        Asteroids.erase(Asteroids.begin() + index);
    }

}
