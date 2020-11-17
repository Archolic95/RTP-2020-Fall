#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.listDevices();
    grabber.setDeviceID(0);
    grabber.setup(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    cam.enableOrtho();

    

    for (int y = 1; y < grabber.getHeight() - 1; y += 5) {
        ofPolyline line;
        int midx = (int)grabber.getWidth() / 2;
        int midy = (int)grabber.getHeight() / 2;
        float midintensity = grabber.getPixels().getColor(midx, y).getBrightness();
        for (int x = 1; x < grabber.getWidth() - 1; x++) {
            float brightness = grabber.getPixels().getColor(x, y).getBrightness();
            float edgeintensity =  2* grabber.getPixels().getColor(x - 1, y).getBrightness() + 2 * grabber.getPixels().getColor(x + 1, y).getBrightness()
               - grabber.getPixels().getColor(x-1, y-1).getBrightness() - grabber.getPixels().getColor(x-1, y + 1).getBrightness()
                + grabber.getPixels().getColor(x+1, y+1).getBrightness() + grabber.getPixels().getColor(x + 1, y - 1).getBrightness();
            float offset = ofMap(edgeintensity, -255, 255, -100, 100);
            if (x > midx)
            {
                offset = offset*sin((x-midx));
            }
            else 
            {
                offset = offset * sin(x);
            }
            
            line.addVertex(x - grabber.getWidth() / 2, (grabber.getHeight() - y - 1) - grabber.getHeight() / 2, offset);
        }
        line = line.getSmoothed(10);
        line.draw();
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
