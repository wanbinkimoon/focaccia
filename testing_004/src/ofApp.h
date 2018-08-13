#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGuiExtended.h"

class Rondella : public ofxBox2dCircle {
	public:
		void draw() {
			ofPushMatrix();
				ofTranslate(getPosition());
				ofRotateZDeg(getRotation());
				ofFill(); ofSetHexColor(0xf6c738);
				ofDrawCircle(0, 0, getRadius());
			ofPopMatrix();
		}
};

// --------------------------------------------------------------

class ofApp : public ofBaseApp{

	public:
		// ofEasyCam cam;
		ofxBox2d box2d;
		vector   <shared_ptr<Rondella> > particles;

		ofParameter<int> quantity;
		ofParameter<float> gravity1;
		ofParameter<float> gravity2;
		ofxGui panel;

		// --------------------------------------------------------------
		
		int windowSide = 1000;
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
