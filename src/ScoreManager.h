//
//  ScoreManager.h
//  gravityPong
//
//  Created by Robert Homewood on 17/03/2017.
//
//

#ifndef ScoreManager_h
#define ScoreManager_h

#include <stdio.h>
#include "ofMain.h"

class ScoreManager {
public:
    void setup();
    void update();
    void draw();
    
    void addScore(int, int);
    
    int player1Score, player2Score;
    int posX, posY;
    
    ScoreManager();
    
};

#endif /* ScoreManager_h */
