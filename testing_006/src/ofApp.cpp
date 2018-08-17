#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(window, window);
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){	
	boxW = (ofGetWidth() / grid) - padding;
	boxH = (ofGetHeight() / grid) - padding;
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();

	for (int i = 0; i < grid; ++i){
		for (int j = 0; j < grid; ++j){

			float x = (ofGetWidth() / grid) * i + (boxW / 2) + padding - centerX;
			float y = (ofGetHeight() / grid) * j - boxH - padding - centerY;
			float z = 0;
			ofVec3f boxPos(x, y, z);
			float dist = boxPos.distance(ofVec3f(mouseX - centerX,  (mouseY * -1) + (centerY + (boxH * 2)), 0));
			z = ofMap(dist, 0, 300, -100, 0, true);
			float sizeMult = ofMap(dist, 0, 300, .75, 1, true);

			ofSetLineWidth(2);
			ofNoFill(); ofSetColor(255, 100, 100);
			ofDrawBox(x, y, z - 100, (boxW + 2) * sizeMult, (boxH + 2) * sizeMult, (boxW + 2) * sizeMult);

			int alpha = ofMap(dist, 0, 300, 100, 50, true);
			ofFill(); ofSetColor(100, 100, 255, alpha);
			ofDrawBox(x, y, z - 100, boxW * sizeMult, boxH * sizeMult, boxW * sizeMult);
			
			z = ofMap(dist, 0, 300, (100 + (boxW / 2)) * -1 , (boxW / 2), true);
			// x = x + ofRandom(-boxW / 2, boxW / 2);
			// y = y + ofRandom(-boxH / 2, boxH / 2);
			sizeMult = ofMap(dist, 0, 300, 1, 2, true);

			ofSetLineWidth(1);
			ofNoFill(); ofSetColor(100, 255, 100);
			ofSetSphereResolution(3);
			ofDrawSphere(x, y, z - 100, (boxW / 8) * sizeMult);

		}
	}


	// ofNoFill(); ofSetColor(255, 100, 100);
	// ofDrawSphere(0, 0, 0, boxH);
	// ofNoFill(); ofSetColor(100, 255, 100);
	// ofDrawBox(0, 0, 0, 2);
	// ofNoFill(); ofSetColor(100, 100, 255);
	// ofLine(0, -centerY, 0, centerY);
	// ofLine(-centerX, 0, centerX, 0);
	// ofSetColor(200);
	// ofDrawBitmapString(ofToString(mouseX), 20, ofGetHeight() - 20);
	// ofDrawBitmapString(ofToString(mouseY), 20, ofGetHeight() - 40);

	cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
