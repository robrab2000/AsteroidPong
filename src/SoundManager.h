//
//  SoundManager.h
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//

#ifndef SoundManager_h
#define SoundManager_h

#include <stdio.h>
#include "ofMain.h"

class SoundManager {
public:
    void setup(bool);
    void update();
    void playPong(float);
    void playPing(float);
    void playWall(float);
    void ballRelease(float);
    void playMusic();
    
    ofSoundPlayer pingSound;
    ofSoundPlayer pongSound;
    ofSoundPlayer wallSound;
    ofSoundPlayer releaseBall;
    ofSoundPlayer music;
    
    bool audioOn;
};

#endif /* SoundManager_h */
