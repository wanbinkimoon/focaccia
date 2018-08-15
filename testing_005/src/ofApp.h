#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGuiExtended.h"

class RondellaSpecs {
public:
	ofColor color;
	int     id;
};

// --------------------------------------------------------------

class Rondella : public ofxBox2dCircle {
	public:
		void setupTheCustomData() {
				static int colors[] = {0xcae72b, 0xe63b8f, 0x2bb0e7};
				
				setData(new RondellaSpecs());
				RondellaSpecs * specs = (RondellaSpecs*)getData();
				
				specs->id = ofRandom(0, 100);
				specs->color.setHex(colors[(int)ofRandom(0, 3)]);
			}
	
		void draw() {
			RondellaSpecs * specs = (RondellaSpecs*)getData();
			ofPushMatrix();
				ofTranslate(getPosition());
				ofRotateZDeg(getRotation());
				
				ofFill(); ofSetColor(specs->color);

				ofDrawCircle(0, 0, getRadius());
			ofPopMatrix();
		}

};

// --------------------------------------------------------------

class ofApp : public ofBaseApp{

	public:
				// Audio 
		float smoothedVol;
		float scaledVol = 0;
		vector <float> volHistory;
		vector <float> mono;

		void audioIn(ofSoundBuffer &input);
		void audioSetup();
		void audioUpdate();
		void audioLineDraw();
		void audioPanelSetup();
    ofSoundStream soundStream;

    // --------------------------------------------------------------
    
		// ofEasyCam cam;
		ofxBox2d box2d;
		vector <shared_ptr<Rondella> > particles;
		vector <shared_ptr<ofxBox2dEdge> > container;
		vector <ofVec2f> containerVec;

		ofParameter<int> quantity;
		ofParameter<float> gravity1;
		ofParameter<float> gravity2;
		ofParameter<int> resolution;
		ofParameter<int> radius;
		ofParameter<float> bounce;
		ofParameter<float> circleRotation;
		ofParameter<float> minDis;
		ofParameter<float> soundRatio;
		ofParameter<bool> showContainer;
		ofParameter<bool> showContainerBg;
		ofParameter<bool> magneticCenter;

		ofxGuiGroup *monitorVal;
		ofxGui panel;

		void controlSetup();
		void shapeSetup();
		void shapeUpdate();
		void shapeDraw();

		// --------------------------------------------------------------
		
		int windowSide = 1000;
		int center = windowSide / 2;
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
