#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofEasyCam cam;

		int grid = 11;
		int padding = 20;
		int border = 40;
		int boxW;
		int boxH;

		// --------------------------------------------------------------
		int window = 1000;
		int centerX = ofGetWidth() / 2;
		int centerY = ofGetHeight() / 2;

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
