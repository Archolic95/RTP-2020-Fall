#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    font.load("ariblk.ttf", 120, true, true, true);

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

    ofBackground(255);

    vector < ofPath > paths = font.getStringAsPoints("Harvard\nGSD\nMDES");

    ofTranslate(20, 190);

    ofSeedRandom(ofGetElapsedTimef()*10);

    for (int i = 0; i < paths.size(); i++) {
        paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector < ofPolyline > lines = paths[i].getOutline();

        ofBeginShape();

        for (int j = 0; j < lines.size(); j++) {

            lines[j].setClosed(true);
            lines[j] = lines[j].getResampledBySpacing(2);
            //lines[j] = lines[j].getSmoothed(mouseX * 0.1);

            if (j != 0) ofNextContour();

            for (int k = 0; k < lines[j].size(); k++) {
                double dist = sqrt(pow(mouseX - 20 - lines[j][k].x, 2) + pow(mouseY - lines[j][k].y - 190, 2));

                double a = ofMap(dist, 0, 600, 0, 255);
                double b = ofMap(j, 0, lines.size(), 0, 255);

                ofSetColor(255 - a/2,122 +a/2,b, 255-a/4);

                lines[j][k].x += ofRandom(-dist/40, dist/40);
                //lines[j][k].y += ofRandom(-mouseX/5, mouseX/5);

                ofVertex(lines[j][k].x, lines[j][k].y);
            }
            //
            //lines[j].draw();

        }

        ofEndShape();

    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}