//
//  Asteroid.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//

#include "Asteroid.h"

// Method to initialize the asteroid
void Asteroid::setup(ofVec2f _position, ofVec2f _velocity, int _level) {
    // Assign pointers
    position = _position;
    velocity = _velocity;
    setSize(_level);
    // Set a color for the asteroid
    myColor = ofColor(255, 255, 255);
    // Set initial rotate position
    rotator = ofRandom(360);
    // Set rotation rate
    rotateRate = ofRandom(-1, 1);
}

// Method to update the asteroid
void Asteroid::update() {
    // Call function to update the asteroid's position
    calcPos();
}

// Method to draw the asteroid
void Asteroid::draw() {
    ofPushMatrix();
        // Set the colour of the asteroid
        ofSetColor(myColor);
        // Set the resolution of the circle
        ofSetCircleResolution(5);
        // Move the position of the canvas
        ofTranslate(position.x, position.y);
        //Rotate the canvas
        ofRotate(rotator);
        // Set to No Fill
        ofNoFill();
        // Draw the actual asteroid
        ofDrawCircle(0, 0, dim);
        // Set to Fill again
        ofFill();
    ofPopMatrix();
}

// Method to set the size of the asteroid based on it's level
void Asteroid::setSize(int size) {
    level = size;
    switch(size) {
        case 3:
            dim = DIM3;
            break;
        case 2:
            dim = DIM2;
            break;
        case 1:
            dim = DIM1;
            break;
    }
}

// Method to calculate the movement of the asteroid
void Asteroid::calcPos() {
    // Calculate the position based on velocity
    position += velocity;
    // Calculate the rotation
    rotator += rotateRate * velocity.x;
}
