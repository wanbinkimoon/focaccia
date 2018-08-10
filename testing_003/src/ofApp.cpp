#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(windowSide, windowSide);
	ofBackground(0);

	ofEnableLighting();
	ofEnableDepthTest();

	light1.setAreaLight(100, 100);
	light1.setAmbientColor(ofColor(50,50,50));
	light1.setPosition(ofVec3f(0, -windowSide, windowSide / 8));
	light1.lookAt(ofVec3f(0, 0, 0));
	light1.enable();

	light2.setAreaLight(100, 100);
	light2.setAmbientColor(ofColor(100,100,100));
	light2.setPosition(ofVec3f(0, windowSide, windowSide / 8));
	light2.lookAt(ofVec3f(0, 0, 0));
	light2.enable();

	light3.setAreaLight(100, 100);
	// light3.setAmbientColor(ofColor(200,200,200));
	light3.setPosition(ofVec3f(windowSide, 0, -windowSide / 8));
	light3.lookAt(ofVec3f(0, 0, 0));
	light3.enable();

	light4.setAreaLight(100, 100);
	// light4.setAmbientColor(ofColor(200,200,200));
	light4.setPosition(ofVec3f(-windowSide, 0, -windowSide / 8));
	light4.lookAt(ofVec3f(0, 0, 0));
	light4.enable();

	light5.setAreaLight(10, 10);
	// light5.setAmbientColor(ofColor(200,200,200));
	light5.setPosition(ofVec3f(0, 0, windowSide));
	light5.lookAt(ofVec3f(0, 0, 0));
	light5.enable();
	
	material.setAmbientColor(ofColor(0));
	material.setDiffuseColor(ofColor(200, 200, 200));
	// material.setSpecularColor(ofColor(120, 120, 120));
	material.setShininess(70);

	radius = 200;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	light1.draw();
	light2.draw();
	light3.draw();
	light4.draw();
	light5.draw();

	ofSetColor(255);
	material.begin();
	// ofDrawSphere(0, 0, 0, windowSide);
	ofDrawSphere(0, 0, 0, radius);
	material.end();
	
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
