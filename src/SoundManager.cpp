//
//  SoundManager.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 12/04/2017.
//
//
//  music courtesy of
//
//
//

#include "SoundManager.h"

void SoundManager::setup(bool _audioOn) {
    // Set up the soundPlayers
    pongSound.setMultiPlay(true);
    pingSound.setMultiPlay(true);
    wallSound.setMultiPlay(true);
    explosionSound.setMultiPlay(true);
    explosionSound.setVolume(0.4);
    wallSound.setVolume(0.25);
    releaseBall.setMultiPlay(true);
    music.setLoop(true);
    music.setVolume(0.4);
    
    // Load the sounds
    pongSound.load("pong.mp3");             // sourced from https://www.freesound.org/people/kickhat/sounds/264447/
    pingSound.load("ping.wav");             // sourced from https://www.freesound.org/people/n_audioman/sounds/273766/
    wallSound.load("wall.wav");             // sourced from https://www.freesound.org/people/NoiseCollector/sounds/4359/
    explosionSound.load("explosion.wav");   // sourced from https://www.freesound.org/people/thehorriblejoke/sounds/259962/
    releaseBall.load("release.mp3");        // sourced from https://www.freesound.org/people/kickhat/sounds/264447/
    music.load("RoccoW_-_Fuckaboing.mp3");  // sourced from http://freemusicarchive.org/music/RoccoW/
    
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

void SoundManager::playExplosion(float pan) {
    if (audioOn) {
        explosionSound.play();
        explosionSound.setPan(pan);
    }
}

void SoundManager::playMusic() {
    if (audioOn) {
        music.play();
    }
}
