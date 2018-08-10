#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1000, 1000);
	ofBackground(50, 100, 255);

	resolution = 100;
	area = 200;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	int sideResolution = ofGetHeight() / resolution;
	radius = resolution / sideResolution;

	ofVec2f mouseP(mouseX, mouseY);

	for (int x = 0; x < resolution; ++x){
		for (int y = 0; y < resolution; ++y){
			ofVec2f v;
			v.x = x * sideResolution + radius;
			v.y = y * sideResolution + radius;

			float distance = v.distance(mouseP);
			float radiusElab = ofMap(distance, 0, area, 0, radius);
			ofDrawCircle(v.x, v.y, radiusElab);
		}
	}
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
	area = area * 2;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	area = area / 2;
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
