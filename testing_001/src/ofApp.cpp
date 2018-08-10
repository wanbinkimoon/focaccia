#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1000, 1000);
	ofBackground(0);

	circleRes = 20;
	circleRadius = 100;
	circleDistance = 200;
	pointRadius = 2;
	timeRall = 0.005;
}

//--------------------------------------------------------------
void ofApp::update(){
 	cicleOne.clear(); cicleTwo.clear(); cicleThree.clear(); cicleFour.clear();
	float timePassing = ofGetFrameNum() * timeRall;
	
	for (unsigned int i = 0; i < circleRes; ++i) {
		float rawAngle = ofMap(i, 0, circleRes, -PI, PI);
		float angle = timePassing + rawAngle;

		float x = circleRadius * cos(angle);
		float y = circleRadius * sin(angle);
		float z = circleRadius * sin(angle) * cos(angle);

		cicleOne.push_back(ofVec3f(x - circleDistance, y - circleDistance, z));
		cicleTwo.push_back(ofVec3f(x + circleDistance, y - circleDistance, z));
		cicleThree.push_back(ofVec3f(x + circleDistance, y + circleDistance, z));
		cicleFour.push_back(ofVec3f(x - circleDistance, y + circleDistance, z));
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	ofRotateZ(45);

	ofBeginShape();
	for (unsigned int j = 0; j < circleRes; j++){
		ofSetColor(100, 250, 150);
		ofVec3f v1 = cicleOne[j];
		ofVertex(v1.x, v1.y, v1.z);
	}
	ofEndShape(true);

	for (unsigned int j = 0; j < circleRes; j++){
		ofVec3f v1 = cicleOne[j];
		ofVec3f v2 = cicleTwo[j];
		ofVec3f v3 = cicleThree[j];
		ofVec3f v4 = cicleFour[j];

		// ofDrawCircle(v1.x, v1.y, 0, pointRadius);
		// ofDrawCircle(v2.x, v2.y, 0, pointRadius);
		// ofDrawCircle(v3.x, v3.y, 0, pointRadius);
		// ofDrawCircle(v4.x, v4.y, 0, pointRadius);

		// --------------------------------------------------------------
		
		ofSetColor(250, 120, 50);
		ofDrawLine(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z);
		ofDrawLine(v2.x, v2.y, v2.z, v3.x, v3.y, v3.z);
		ofDrawLine(v3.x, v3.y, v3.z, v4.x, v4.y, v4.z);
		ofDrawLine(v4.x, v4.y, v4.z, v1.x, v1.y, v1.z);
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
