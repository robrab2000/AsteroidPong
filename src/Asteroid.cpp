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
    
}

// Method to update the asteroid
void Asteroid::update() {
    calcPos();
}

// Method to draw the asteroid
void Asteroid::draw() {
    ofPushMatrix();
    ofSetColor(myColor);
    ofTranslate(position.x, position.y);
    ofDrawCircle(0, 0, dim);
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
    position += velocity;
}
