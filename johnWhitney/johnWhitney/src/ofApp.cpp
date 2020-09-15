#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	//const PI = 3.1415926;
	float xorig = 400;
	float yorig = 400;

	int n = 12;
	float r0 = 600;
	float t = ofGetElapsedTimef() / 8;
	//float radius = r0 * sin(t);
	//float x = xorig + radius * cos(t);
	//float y = yorig + radius * sin(t);
	//ofDrawCircle(x, y, radius);

	for (int j = 0; j < n; j++)
	{
		float radius = r0 * sin(t - asin(1-(float)j / n));
		int n_p = 1440;
		float angle = (float) 2 * PI/n_p;

		for (int i = 0; i < n_p; i++)
		{
			int t_in = (int)(t * 4);
			int l = i / 255;
			int r = (i) % 255;
			int g = (i) % 255;
			int b = (i) % 255;

			ofSetColor(90 + 127 * sin(i * 0.02), 75 + 75*sin(i * 0.01), 200 + 200 * sin(i * 0.05));


			//cout << t_in;
			float x2 = xorig - radius * (cos(i * angle + 2*t));
			float y2 = yorig - radius * (sin(i * angle + 2*t));
			ofDrawCircle(x2, y2, 5);
		}
	}


	//trail.addVertex(x, y);
	//trail.draw();
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
