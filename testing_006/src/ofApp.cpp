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
	ofNoFill(); ofSetColor(255);
	cam.begin();

	for (int i = 0; i < grid; ++i){
		for (int j = 0; j < grid; ++j){
			float x = (i * (ofGetWidth() / grid)) + boxW + (padding / 2) - centerX;
			float y = (j * (ofGetHeight() / grid)) + boxH + (padding / 2) - centerY;
			ofDrawBox(x, y, 0, boxW, boxH, 100);
		}
	}

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
