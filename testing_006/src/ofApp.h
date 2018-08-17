#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofEasyCam cam;

		int grid = 15;
		int padding = 20;
		int border = 40;
		float boxW;
		float boxH;

		// --------------------------------------------------------------
		
		int window = 1000;
		float centerX = ofGetWidth() / 2;
		float centerY = ofGetHeight() / 2;

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
