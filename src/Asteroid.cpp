//
//  Asteroid.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//

#include "Asteroid.h"
void Asteroid::setup(ofVec2f _position, ofVec2f _velocity, int _level) {
    position = _position;
    velocity = _velocity;
    setSize(_level);
    
    // Set the possible asteroid sizes
    dim1 = 30;
    dim2 = 20;
    dim3 = 10;
}

void Asteroid::update() {
    
}

void Asteroid::draw() {
    ofDrawCircle(position.x, position.y, dim);
    
}

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
