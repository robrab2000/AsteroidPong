//
//  gui.h
//  effingRidiculousPong
//
//  Created by Robert Homewood on 10/04/2017.
//
//

#ifndef gui_h
#define gui_h

#include "ScoreManager.h"
#include "ofxOsc.h"

#include <stdio.h>

class gui {
public:
    void setup(ScoreManager*, ofxOscSender*);
    void update();
    void draw();
    void resetGui();
    void holdBall();
    void releaseBall();
    void player1SliderPos(float);
    void player2SliderPos(float);
    
    
    bool startGame();
    
    
    ScoreManager* scoreManager;
    ofxOscSender* sender;
};

#endif /* gui_h */
