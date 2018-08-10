#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

		int windowSide = 1000;

		// --------------------------------------------------------------

		ofEasyCam cam;
		ofLight	light1, light2, light3, light4, light5;
		ofMaterial material;

		ofParameter<int> resolution;
		ofParameter<float> radius;
		ofParameter<int> area;

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
