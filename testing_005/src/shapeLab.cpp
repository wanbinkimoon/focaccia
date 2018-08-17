#include "ofApp.h"

void ofApp::controlSetup(){
	quantity.set("ceter particles", 10, 0, 1000);
	quantityBorders.set("sides particles", 1, 0, 1000);
	gravity1.set("gravity x", 0, -100, 100);
	gravity2.set("gravity y", 10, -100, 100);
	resolution.set("container sides", 3, 3, 20);
	radius.set("container radius", 250, 100, 500);
	circleRotation.set("container rotation", 0.001, 0, 0.05);
	minDis.set("force radius", 40, 0, 200);
	soundRatio.set("sound max multiplier", 1.25, 0, 5);
	magneticCenter.set("magnetic center", false);
	showContainer.set("container borders", false);
	showContainerBg.set("container background", false);
	invertCircle.set("invert circle", false);

//  monitorVal->add<ofxGuiValuePlotter>(bounce.set("bounce", 0, 0, 9));
	
	panel.add(
		quantity,
		quantityBorders, 
		gravity1,
		gravity2,
		resolution,
		radius,
		circleRotation,
		minDis,
		soundRatio,
		magneticCenter,
		showContainer,
		invertCircle,
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
	if(invertCircle) {
		bounce = ofMap(scaledVol, 0, 1, soundRatio, 1);
	} else  {
		bounce = ofMap(scaledVol, 0, 1, 1, soundRatio);
	}
	// clear container vector before updates
  container.clear();
  containerVec.clear();

  // define container 
  auto corner = std::make_shared<ofxBox2dEdge>();
  for (unsigned int i = 0; i < resolution + 1; ++i) {
    float angle = ofMap(i, 0, resolution, -PI, PI) + (circleRotation * ofGetFrameNum());
    float x = ((radius * bounce) * cos(angle)) + centerX;
    float y = ((radius * bounce) * sin(angle)) + centerY;
    corner.get()->addVertex(x, y);
    containerVec.push_back(ofVec2f(x, y));
  }
  corner.get()->create(box2d.getWorld());
  container.push_back(corner);

  // add particles to the system 
	for (unsigned int i = 0; i < quantity && particles.size() < quantity; ++i){
		auto p = std::make_shared<Rondella>();
		float r = ofRandom(4, 20);
		float x = ofRandom(centerX - 100, centerX + 100);
		float y = ofRandom(centerY - 100, centerY + 100);

		p.get()->setPhysics(1.0, 0.5, 0.3);
		p.get()->setup(box2d.getWorld(), x, y, r);
		p.get()->setVelocity(ofRandom(-10, 10), ofRandom(-10, 10));
		p.get()->setupTheCustomData();
		particles.push_back(p);
	}

	for (unsigned int i = 0; i < quantityBorders && particlesSides.size() < quantityBorders; ++i){
		auto p = std::make_shared<Rondella>();
		float r = ofRandom(4, 20);

		float x1 = 0;
		float x2 = ofGetWidth();
		float x;

		if (i % 2 == 0) {
			x = x1;
		} else  {
			x = x2;
		}

		float y1 = 0;
		float y2 = ofGetHeight();
		float y;
		if (i % 2 == 0) {
			y = y1;
		} else  {
			y = y2;
		}

		p.get()->setPhysics(1.0, 0.5, 0.3);
		p.get()->setup(box2d.getWorld(), x, y, r);
		p.get()->setVelocity(ofRandom(-10, 10), ofRandom(-10, 10));
		p.get()->setupTheCustomData();
		particlesSides.push_back(p);
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


	ofVec2f magnet(centerX, centerY);

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
	
	for(unsigned int i = 0; i < particlesSides.size(); i++) {

		if(magneticCenter) {
			float repulsionForce = 9;
			float attractionForce = 4;
			float dis = magnet.distance(particlesSides[i].get()->getPosition());
			float invisibleBorder = minDis * soundRatio;

			if(dis < invisibleBorder) particlesSides[i].get()->addRepulsionForce(magnet, repulsionForce);
			else particlesSides[i].get()->addAttractionPoint(magnet, attractionForce);
		}

		particlesSides[i].get()->draw();
    
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
