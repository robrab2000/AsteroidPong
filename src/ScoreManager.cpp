//
//  ScoreManager.cpp
//  gravityPong
//
//  Created by Robert Homewood on 17/03/2017.
//
//

#include "ScoreManager.h"

ScoreManager::ScoreManager() {
    
}

void ScoreManager::setup() {
    player1Score = 0;
    player2Score = 0;
}

void ScoreManager::draw() {
    ofDrawBitmapString("player 2: " + ofToString(player2Score), ofGetWidth() * 0.2, 50);
    ofDrawBitmapString("player 1: " + ofToString(player1Score), ofGetWidth() * 0.7, 50 );
}

void ScoreManager::addScore(int playerNumber, int score) {
    
    
    if (playerNumber == 1) {
        player1Score += score;
    }
    else if (playerNumber == 2) {
        player2Score += score;
    }
}
