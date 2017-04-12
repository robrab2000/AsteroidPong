//
//  Asteroid.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//

#include "Asteroid.h"
void Asteroid::setup(float _posX, float _posY, int _level) {
    posX = _posX;
    posY = _posY;
    setSize(_level);
}

void Asteroid::update() {
    
}

void Asteroid::draw() {
    ofDrawCircle(posX, posY, dim);
    
}

void Asteroid::setSize(int size) {
    level = size;
    switch(size) {
        case 3:
            dim = 20;
            break;
        case 2:
            dim = 10;
            break;
        case 1:
            dim = 5;
            break;
    }
}
