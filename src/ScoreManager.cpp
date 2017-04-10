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
    
    posX = 100;
    posY = 100;
}

void ScoreManager::draw() {
    ofDrawBitmapString("player 1: " + ofToString(player1Score), posX, posY);
    ofDrawBitmapString("player 2: " + ofToString(player2Score), posX, posY + 20);
}

void ScoreManager::addScore(int playerNumber) {
    
    
    if (playerNumber == 1) {
        
        player1Score++;
        //cout<<player1Score<<endl;

        //ofLog(OF_LOG_NOTICE, "player 1 score increment");
    }
    else if (playerNumber == 2) {
        player2Score++;
        //ofLog(OF_LOG_NOTICE, "player 2 score increment");
    }
}
