#include "ofApp.h"

void ofApp::controlSetup(){
	quantity.set("number of circles", 10, 0, 1000);
	gravity1.set("gravity x", 0, -100, 100);
	gravity2.set("gravity y", 10, -100, 100);
	resolution.set("container sides", 5, 3, 40);
	radius.set("container radius", 250, 100, 500);
	circleRotation.set("container rotation", 0.001, 0, 0.05);
	minDis.set("force radius", 40, 0, 200);
	soundRatio.set("sound max multiplier", 1.25, 0, 5);
	magneticCenter.set("magnetic center", false);
	showContainer.set("container borders", false);
	showContainerBg.set("container background", false);

//  monitorVal->add<ofxGuiValuePlotter>(bounce.set("bounce", 0, 0, 9));
	
	panel.add(
		quantity,
		gravity1,
		gravity2,
		resolution,
		radius,
		circleRotation,
		minDis,
		soundRatio,
		magneticCenter,
		showContainer,
		showContainerBg);
}

// --------------------------------------------------------------

void ofApp::shapeSetup(){
	box2d.init();
	// box2d.createGround();
	box2d.createBounds();
	box2d.setFPS(60.0);
};

// --------------------------------------------------------------

void ofApp::shapeUpdate(){
	box2d.setGravity(gravity1, gravity2);

	// working with sound 
	bounce = ofMap(scaledVol, 0, 1, 1, soundRatio);

	// clear container vector before updates
  container.clear();
  containerVec.clear();

  // define container 
  auto corner = std::make_shared<ofxBox2dEdge>();
  for (unsigned int i = 0; i < resolution + 1; ++i) {
    float angle = ofMap(i, 0, resolution, -PI, PI) + (circleRotation * ofGetFrameNum());
    float x = ((radius * bounce) * cos(angle)) + center;
    float y = ((radius * bounce) * sin(angle)) + center;
    corner.get()->addVertex(x, y);
    containerVec.push_back(ofVec2f(x, y));
  }
  corner.get()->create(box2d.getWorld());
  container.push_back(corner);

  // add particles to the system 
	for (unsigned int i = 0; i < quantity && particles.size() < quantity; ++i){
		auto p = std::make_shared<Rondella>();
		float r = ofRandom(4, 20);
		float x = ofRandom(center - 100, center + 100);
		float y = ofRandom(center - 100, center + 100);

		p.get()->setPhysics(1.0, 0.5, 0.3);
		p.get()->setup(box2d.getWorld(), x, y, r);
		p.get()->setVelocity(ofRandom(-10, 10), ofRandom(-10, 10));
		p.get()->setupTheCustomData();
		particles.push_back(p);
	}

	// particles.erase(particles.begin(), particles.begin()+1);

	box2d.update();

};

// --------------------------------------------------------------

void ofApp::shapeDraw(){
	if(showContainerBg) {
	  ofFill(); ofSetColor(255, 30);
	  ofBeginShape();
		for(unsigned int i = 0; i < containerVec.size(); i++) {
			ofVertex(containerVec[i].x, containerVec[i].y);
		}
	  ofEndShape();
	}


	ofVec2f magnet(center, center);

	for(unsigned int i = 0; i < particles.size(); i++) {

		if(magneticCenter) {
			float repulsionForce = 9;
			float attractionForce = 4;
			float dis = magnet.distance(particles[i].get()->getPosition());
			float invisibleBorder = minDis * soundRatio;

			if(dis < invisibleBorder) particles[i].get()->addRepulsionForce(magnet, repulsionForce);
			else particles[i].get()->addAttractionPoint(magnet, attractionForce);
		}

		particles[i].get()->draw();
	}
	
	if(showContainer) {
	  ofNoFill(); ofSetColor(255);
		for(unsigned int i = 0; i < container.size(); i++) {
			container[i].get()->draw();
		}
	}

	box2d.drawGround();
};

// --------------------------------------------------------------
