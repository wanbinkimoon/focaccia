#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// ofSetWindowShape(windowSide, windowSide);
	ofSetFullscreen(true);
	centerX = ofGetWidth() / 2;
	centerY = ofGetHeight() / 2;
	
	ofBackground(0);
	controlSetup();
	shapeSetup();

	audioSetup();
}

//--------------------------------------------------------------
void ofApp::update(){
	audioUpdate();
	shapeUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(200);
 ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, ofGetHeight() - 20);
	// ofDrawBitmapString(ofToString(bounce), 20, 40);
	
	shapeDraw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case 'c':
			particles.clear();
			break;
		case 'o':
			bounce += 10;
			break;
		case 'p':
			bounce -= 10;
			break;
		case 'b':
			bounce = 0;
			break;
	}
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
