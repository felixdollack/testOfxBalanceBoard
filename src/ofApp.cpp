#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
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

    // draw individual sensors (corners) of wiiFit
    ofDrawCircle(0.1 * screen_width, 0.1 * screen_height, 100 * this->balance_data.top_left);
    ofDrawCircle(0.9 * screen_width, 0.1 * screen_height, 100 * this->balance_data.top_right);
    ofDrawCircle(0.1 * screen_width, 0.9 * screen_height, 100 * this->balance_data.bottom_left);
    ofDrawCircle(0.9 * screen_width, 0.9 * screen_height, 100 * this->balance_data.bottom_right);

    // draw virtual X axis of wiiFit
    float xpos = (0.1 * screen_width) + ((0.8 * screen_width) * this->balance_data.virtual_x);
    ofDrawLine(clearance,                clearance,
               screen_width - clearance, clearance);                 // x line top
    ofDrawLine(clearance,                screen_height - clearance,
               screen_width - clearance, screen_height - clearance); // x line bottom
    ofDrawCircle(xpos, clearance,                 circle_size);      // circle top
    ofDrawCircle(xpos, screen_height - clearance, circle_size);      // circle bottom
    ofDrawLine(xpos, clearance,
               xpos, screen_width - clearance);                      // intersection X

    // draw virtual Y axis of wiiFit
    float ypos = (0.9 * screen_height) - ((0.8 * screen_height) * this->balance_data.virtual_y);
    ofDrawLine(clearance, (0.1 * screen_height),
               clearance, (0.9 * screen_height));                    // y line left
    ofDrawLine(screen_width - clearance, (0.1 * screen_height),
               screen_width - clearance, (0.9 * screen_height));     // y line right
    ofDrawCircle(clearance,                ypos, circle_size);       // circle left
    ofDrawCircle(screen_width - clearance, ypos, circle_size);       // circle right
    ofDrawLine(clearance, ypos,
               screen_width - clearance, ypos);                      // intersection Y

    // draw center of mass and weight
    ofDrawCircle(xpos, ypos, 100 * this->balance_data.sum);

    // draw absolute center
    ofSetColor(ofColor::red);
    ofDrawLine((screen_width/2) - clearance, (screen_height/2),
               (screen_width/2) + clearance, (screen_height/2));
    ofDrawLine((screen_width/2), (screen_height/2) - clearance,
               (screen_width/2), (screen_height/2) + clearance);
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
