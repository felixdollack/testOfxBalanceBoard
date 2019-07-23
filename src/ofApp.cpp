#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // osculator forwarding address: osc.udp://localhost:9000
    int oscPort = 9000;

    // for visualization
    this->screen_width = ofGetWindowWidth();
    this->screen_height = ofGetWindowHeight();

    // create and start thread to receive data
    this->balance_thread = new Balanceboard(oscPort);
    this->balance_thread->start();
}

//--------------------------------------------------------------
void ofApp::update(){
    // update local balance data
    this->balance_data = this->balance_thread->getBalanceData();
}

//--------------------------------------------------------------
void ofApp::draw(){
    float clearance = 25.0f;
    float circle_size = 10.0f;

    ofClear(0);
    ofSetColor(ofColor::royalBlue);

    ofDrawLine(clearance,                clearance,
               screen_width - clearance, clearance);                 // x line top
    ofDrawLine(clearance,                screen_height - clearance,
               screen_width - clearance, screen_height - clearance); // x line bottom
    ofDrawLine(clearance, (0.1 * screen_height),
               clearance, (0.9 * screen_height));                    // y line left
    ofDrawLine(screen_width - clearance, (0.1 * screen_height),
               screen_width - clearance, (0.9 * screen_height));     // y line right

    float xpos1 = (0.9 * screen_width) - ((0.8 * screen_width) * this->balance_data.virtual_x[0]); // top
    float ypos1 = (0.1 * screen_height) + ((0.8 * screen_height) * this->balance_data.virtual_x[1]); // left
    float xpos2 = (0.1 * screen_width) + ((0.8 * screen_width) * this->balance_data.virtual_x[2]); // right
    float ypos2 = (0.9 * screen_height) - ((0.8 * screen_height) * this->balance_data.virtual_x[3]); // bottom

    ofDrawCircle(xpos1, clearance,                 circle_size);      // circle top
    ofDrawCircle(clearance,                ypos1, circle_size);       // circle left
    ofDrawCircle(xpos2, screen_height - clearance, circle_size);      // circle bottom
    ofDrawCircle(screen_width - clearance, ypos2, circle_size);       // circle right
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
    this->screen_width = w;
    this->screen_height = h;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
