#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "Paddle.h"
#include "ScoreManager.h"
#include "ofxOsc.h"
#include "ai.h"


// listen on port 12345
#define RECEIVER_PORT 12345
// send on port 54321
#define SENDER_PORT 54321
#define SENDER_IP "localhost" //"192.168.1.6"
#define NUM_MSG_STRINGS 20
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void checkOSC();
    
    ofxOscReceiver receiver;
    ofxOscSender sender;
    deque<string> messageBuffer;
    int maxBufferSize=20;
    
    void drawNet();
		
    Ball ball;
    ScoreManager scoreManager;
    Paddle player1, player2;
    ai aiPlayer;
};
