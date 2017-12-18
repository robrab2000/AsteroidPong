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
    // Set a resolution for this asteroid
    resolution = (int)ofRandom(5, 5);
    // Define the shape of the asteroid
    defineShape(3 * level, dim);
    // Set the stroke width for the asteroid
    asteroidShape.setStrokeWidth(1);
    // Set the stoke color of the asteroid
    asteroidShape.setStrokeColor(myColor);
    // Set the fill colour of the asteroid
    asteroidShape.setFillColor(ofColor(0,0,0));
}

// Method to update the asteroid
void Asteroid::update() {
    // Call function to update the asteroid's position
    calcPos();
}

// Method to draw the asteroid
void Asteroid::draw() {
    ofPushMatrix();
        // Set the resolution of the circle
        ofSetCircleResolution(resolution);
        // Move the position of the canvas
        ofTranslate(position.x, position.y);
        ofPushMatrix();
            // Create a modifier based on velocity to adjust the opacity
            float opacityMod = ofMap(abs(velocity.x) + abs(velocity.y), 0, 20, 0, 1);
            // Draw the straight trails
            // Set opacity and draw a trail
            ofSetColor(myColor.r, myColor.g, myColor.b, 15 * opacityMod);
            ofDrawLine(0, 0, -velocity.x * 10, -velocity.y * 10);
            // Set opacity and draw a trail
            ofSetColor(myColor.r, myColor.g, myColor.b, 25 * opacityMod);
            ofDrawLine(0, 0, -velocity.x * 9, -velocity.y * 9);
            // Set opacity and draw a trail
            ofSetColor(myColor.r, myColor.g, myColor.b, 25 * opacityMod);
            ofDrawLine(0, 0, -velocity.x * 8, -velocity.y * 8);
    
            // Draw the angled trails
            // Set opacity and draw a trail
            ofSetColor(myColor.r, myColor.g, myColor.b, 50 * opacityMod);
            ofDrawLine(0, dim * 0.75, -velocity.x * 7, -velocity.y * 7);
            // Set opacity and draw a trail
            ofSetColor(myColor.r, myColor.g, myColor.b, 50 * opacityMod);
            ofDrawLine(0, dim * 0.75, -velocity.x * 3.5, -velocity.y * 3.5);
            // Set opacity and draw a trail
            ofSetColor(myColor.r, myColor.g, myColor.b, 50 * opacityMod);
            ofDrawLine(0, dim * -0.75, -velocity.x * 7, -velocity.y * 7);
            // Set opacity and draw a trail
            ofSetColor(myColor.r, myColor.g, myColor.b, 50 * opacityMod);
            ofDrawLine(0, dim * -0.75, -velocity.x * 3.5, -velocity.y * 3.5);
        // End trail matrix
        ofPopMatrix();
        //Rotate the canvas
        ofRotate(rotator);
        // Draw the actual asteroid
        asteroidShape.draw();
//        ofDrawCircle(0, 0, dim - 1);
    
    ofPopMatrix();
}

// Method to set the size of the asteroid based on it's level
void Asteroid::setSize(int size) {
    level = size;
    switch(size) {
        case 4:
            dim = DIM4;
            break;
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

// Method to define the shape of the asteroid
void Asteroid::defineShape(float points, float radius) {
    double slice = 2 *  PI / points;
    for (int i = 0; i < points; i++)
    {
        double angle = slice * i;
        int newX = (int)(0 + radius * cos(angle));
        int newY = (int)(0 + radius * sin(angle));
        ofPoint p = ofPoint(newX, newY);
        ofPoint randomP = ofPoint(ofRandom(-dim * 0.25, dim * 0.25), ofRandom(-dim * 0.25, dim * 0.25));
        asteroidShape.lineTo(p + randomP);
    }
    asteroidShape.close(); // close the shape
}
