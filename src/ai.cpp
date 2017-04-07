//
//  ai.cpp
//  effingRidiculousPong
//
//  Created by Robert Homewood on 07/04/2017.
//
//

#include "ai.h"

void ai::setup(ScoreManager* _scoreManager, Paddle* _player2, Ball* _ball, ofxOscSender* _sender) {
    scoreManager = _scoreManager;
    player2 = _player2;
    ball = _ball;
    sender = _sender;
    
    noise = ofRandom(1);
    
}

void ai::update() {
    calcAction();
}

void ai::draw() {
    
}

void ai::calcAction() {
    //    sendAction(ofNoise(noise) * (ball->y / ofGetHeight()));
    float offset = (1 - (ball->y / ofGetHeight()));
    sendAction(ofNoise(noise));// * offset);
    noise += 0.03;
}

void ai::sendAction(float action) {
//    ofLog(OF_LOG_NOTICE, "test");
    if (player2 != NULL) {
        player2->takeInput(action);
        sendOscMessage(action);
    }
}

void ai::sendOscMessage(float action) {
//    ofLog(OF_LOG_NOTICE, "test");
    ofxOscMessage m;
    m.setAddress( "/1/fader8" );
    m.addFloatArg( action );
    sender->sendMessage( m );
}
