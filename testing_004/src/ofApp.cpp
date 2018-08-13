#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(windowSide, windowSide);
	ofBackground(0);

	quantity.set("number of circles", 10, 0, 100);
	gravity1.set("gravity 1", 0, 0, 100);
	gravity2.set("gravity 2", 10, 0, 100);
	panel.add(quantity, gravity1, gravity2);

	box2d.init();
	box2d.createGround();
	box2d.setFPS(60.0);
}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.setGravity(gravity1, gravity2);

	for (int i = 0; i < quantity && particles.size() < quantity; ++i){
		auto p = std::make_shared<Rondella>();
		float r = ofRandom(4, 20);
		float x = ofRandom(0, windowSide);
		float y = ofRandom(0, windowSide / 2);

		p.get()->setPhysics(1.0, 0.5, 0.3);
		p.get()->setup(box2d.getWorld(), x, y, r);
		p.get()->setVelocity(ofRandom(-10, 10), ofRandom(-10, 10));
		particles.push_back(p);
	}

	particles.erase(particles.begin(), particles.begin()+1);

	box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i=0; i<particles.size(); i++) {
		particles[i].get()->draw();
	}
	box2d.drawGround();
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
