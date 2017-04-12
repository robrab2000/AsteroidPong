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
    position = _position;
    velocity = _velocity;
    setSize(_level);
    myColor = ofColor(255, 255, 255);
    
    // Set the possible asteroid sizes
    dim1 = 30;
    dim2 = 20;
    dim3 = 10;
}

// Method to update the asteroid
void Asteroid::update() {
    
}

// Method to draw the asteroid
void Asteroid::draw() {
    ofPushMatrix();
    ofSetColor(myColor);
    ofDrawCircle(position.x, position.y, dim);
    ofPopMatrix();
}

// Method to set the size of the asteroid based on it's level
void Asteroid::setSize(int size) {
    level = size;
    switch(size) {
        case 3:
            dim = dim3;
            break;
        case 2:
            dim = dim2;
            break;
        case 1:
            dim = dim1;
            break;
    }
}
