#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	for (int i = 0; i < 100; i++) 
	{
		cout << ofRandom(0, 100) << endl;
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofDrawCircle();
    //ofDrawRectangle();
    float w = 900;
    int step = 30;
    float R = step / 2;
    const int iterNum = 30;
    ofBackground(255);
    ofSetColor(0);

    ofSeedRandom(mouseX * 10);
    float offset = step;//mouseY;

    float alpha = ofNoise(0, PI);
    float beta = ofNoise(0, PI);

    for (int i = 0; i < iterNum; i++)
    {
        for (int j = 0; j < iterNum; j++)
        {
            float x = ofMap(j, 0, iterNum, 0, w);
            float y = ofMap(i, 0, iterNum - 1, R, w - R);

            alpha = beta;
            beta = ofRandom(0, PI);
            //ofNoFill();
            if (j == iterNum - 1) 
            {
                ofBeginShape();
                ofVertex(w - step + R * cos(alpha), y + R * sin(alpha));
                ofVertex(w, y + R);
                ofVertex(w, y - R);
                ofVertex(w - step + R * cos(alpha + PI), y + R * sin(alpha + PI));
                ofEndShape(true);
            }
            else 
            {
                if (j == 0)
                {
                    alpha = PI / 2;
                }
                ofBeginShape();
                ofVertex(x + R * cos(alpha), y + R * sin(alpha));
                ofVertex(x + step + R * cos(beta), y + R * sin(beta));
                ofVertex(x + step + R * cos(beta + PI), y + R * sin(beta + PI));
                ofVertex(x + R * cos(alpha + PI), y + R * sin(alpha + PI));
                ofEndShape(true);
            }
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
