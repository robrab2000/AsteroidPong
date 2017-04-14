//
//  ScoreManager.cpp
//  gravityPong
//
//  Created by Robert Homewood on 17/03/2017.
//
//

#include "ScoreManager.h"

// Default constructor
ScoreManager::ScoreManager() {
    
}

// Method to initialize the scoreManager
void ScoreManager::setup() {
    player1Score = 0;
    player2Score = 0;
}

// Method to draw the scoreManager
void ScoreManager::draw() {
    // THIS SHOULD GET MOVED TO THE GUI
    ofDrawBitmapString("player 2: " + ofToString(player2Score), ofGetWidth() * 0.2, 50);
    ofDrawBitmapString("player 1: " + ofToString(player1Score), ofGetWidth() * 0.7, 50 );
}

// Method to increase score for the players
void ScoreManager::addScore(int playerNumber, int score) {
    // If we are increasing player 1's score
    if (playerNumber == 1) {
        // Increase the score
        player1Score += score * GENERAL_MULTIPLIER;
    }
    // If we are increasing player 1's score
    else if (playerNumber == 2) {
        // Increase the score
        player2Score += score * GENERAL_MULTIPLIER;
    }
}
