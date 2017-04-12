//
//  SoundManager.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//

#include "SoundManager.h"

void SoundManager::setup(bool _audioOn) {
    // Set up the soundPlayers
    pongSound.setMultiPlay(true);
    pingSound.setMultiPlay(true);
    wallSound.setMultiPlay(true);
    wallSound.setVolume(0.25);
    releaseBall.setMultiPlay(true);
    music.setLoop(true);
    music.setVolume(0.4);
    
    // Load the sounds
    pongSound.load("pong.mp3");
    pingSound.load("ping.wav");
    wallSound.load("wall.wav");
    releaseBall.load("release.mp3");
    music.load("RoccoW_-_Fuckaboing.mp3");
    
    // Set Audio On or Off
    audioOn = _audioOn;
    
    // Start the music
    playMusic();
}

void SoundManager::update() {
    
}

void SoundManager::playPong(float pan) {
    if (audioOn) {
        pongSound.play();
        pongSound.setPan(pan);
    }
}

void SoundManager::playPing(float pan) {
    if (audioOn) {
        pingSound.play();
        pingSound.setPan(pan);
    }
}

void SoundManager::playWall(float pan) {
    if (audioOn) {
        wallSound.play();
        wallSound.setPan(ofMap(pan, 0, 1, -0.8, 0.8));
    }
}

void SoundManager::ballRelease(float pan) {
    if (audioOn) {
        releaseBall.play();
        releaseBall.setPan(pan);
    }
}

void SoundManager::playMusic() {
    if (audioOn) {
        music.play();
    }
}
