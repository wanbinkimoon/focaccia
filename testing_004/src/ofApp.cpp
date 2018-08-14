#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(windowSide, windowSide);
	ofBackground(0);

	quantity.set("number of circles", 10, 0, 100);
	gravity1.set("gravity x", 0, -100, 100);
	gravity2.set("gravity y", 0, -100, 100);
	circleRes.set("container sides", 20, 3, 100);
	circleRadius.set("container radius", 200, 100, 1000);
	circleRotation.set("container rotation", 0.001, 0, 0.01);
	panel.add(quantity, gravity1, gravity2, circleRes, circleRadius, circleRotation);

	box2d.init();
	// box2d.createGround();
	box2d.createBounds();
	box2d.setFPS(60.0);
}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.setGravity(gravity1, gravity2);

  container.clear();
  containerLine.clear();
  
  auto corner = std::make_shared<ofxBox2dEdge>();
  
  for (unsigned int i = 0; i < circleRes + 1; ++i) {
    float angle = ofMap(i, 0, circleRes, -PI, PI) + (circleRotation * ofGetFrameNum());
    float x = (circleRadius * cos(angle)) + (windowSide / 2);
    float y = (circleRadius * sin(angle)) + (windowSide / 2);
    
    corner.get()->addVertex(x, y);
    containerLine.push_back(ofVec2f(x, y));
  }
  
  corner.get()->create(box2d.getWorld());
  container.push_back(corner);

	for (unsigned int i = 0; i < quantity && particles.size() < quantity; ++i){
		auto p = std::make_shared<Rondella>();
		float r = ofRandom(4, 20);
		float x = ofRandom(0, windowSide);
		float y = ofRandom(0, windowSide / 2);
		p.get()->setPhysics(1.0, 0.5, 0.3);
		p.get()->setup(box2d.getWorld(), x, y, r);
		p.get()->setVelocity(ofRandom(-10, 10), ofRandom(-10, 10));
		particles.push_back(p);
	}

	// particles.erase(particles.begin(), particles.begin()+1);

	box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(unsigned int i = 0; i < particles.size(); i++) {
		particles[i].get()->draw();
	}
	
	for(unsigned int i = 0; i < container.size(); i++) {
		container[i].get()->draw();
	}

	ofBeginShape();
  ofNoFill(); ofSetColor(255);
	for (unsigned int i = 0; i < containerLine.size(); i++) {
    ofVertex(containerLine[i].x, containerLine[i].y);
	}
	ofEndShape(true);
	box2d.drawGround();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case 'c':
			particles.clear();
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
