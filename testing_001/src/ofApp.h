#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofEasyCam cam;

		ofParameter<int> circleRes;
		ofParameter<int> circleRadius;
		ofParameter<int> circleDistance;
		ofParameter<int> pointRadius;
		ofParameter<float> timeRall;

		vector <ofVec3f> cicleOne;
		vector <ofVec3f> cicleTwo;
		vector <ofVec3f> cicleThree;
		vector <ofVec3f> cicleFour;

		// --------------------------------------------------------------
		
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
		
};
