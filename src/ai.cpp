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
//    ofLog(OF_LOG_NOTICE, ofToString(offset));
    float window = 0.5 * ofGetHeight();
    float windowStart = (ofGetHeight() - (ball->y - (window * 0.5))) / ofGetHeight();
    float windowEnd = (ofGetHeight() - (ball->y + (window * 0.5))) / ofGetHeight();
    
    float action = ofMap(ofNoise(noise), 0, 1, windowStart, windowEnd);
    
    ofLog(OF_LOG_NOTICE, "window: " + ofToString(window));
    ofLog(OF_LOG_NOTICE, "windowStart: " + ofToString(windowStart));
    ofLog(OF_LOG_NOTICE, "windowEnd: " + ofToString(windowEnd));
    ofLog(OF_LOG_NOTICE, "Action: " + ofToString(action));
    sendAction(action);
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
