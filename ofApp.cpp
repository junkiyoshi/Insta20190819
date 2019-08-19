#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(270);

	auto radius = 300;
	for (auto theta = 6; theta <= 180 - 8; theta += 8) {
		
		auto deg_len = (ofGetFrameNum() * 5 + theta * 2) % 720;
		if (deg_len > 360) { deg_len = 720 - deg_len; }

		vector<glm::vec3> vertices, sub_vertices;
		for (auto deg = 0; deg <= deg_len; deg += 1) {

			auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD) * sin(theta * DEG_TO_RAD),
				radius * sin(deg * DEG_TO_RAD) * sin(theta * DEG_TO_RAD),
				radius * cos(theta * DEG_TO_RAD));
			vertices.push_back(location);

			auto sub_location = glm::vec3(radius * cos(deg * DEG_TO_RAD) * sin((theta + 6) *DEG_TO_RAD),
				radius * sin(deg * DEG_TO_RAD) * sin((theta + 6) * DEG_TO_RAD),
				radius * cos((theta + 6) * DEG_TO_RAD));
			sub_vertices.push_back(sub_location);
		}

		if (vertices.size() > 0) {

			std::reverse(sub_vertices.begin(), sub_vertices.end());

			ofFill();
			ofSetColor(215, 0, 58);
			ofBeginShape();
			ofVertices(vertices);
			ofVertices(sub_vertices);
			ofEndShape();

			ofNoFill();
			ofSetColor(39);
			ofBeginShape();
			ofVertices(vertices);
			ofVertices(sub_vertices);
			ofEndShape(true);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}