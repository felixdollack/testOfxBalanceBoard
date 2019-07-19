#pragma once

#include "ofMain.h"
#include "balance_board.hpp"

class ofApp : public ofBaseApp{

	public:
        Balanceboard *balance_thread;
        BalanceData balance_data;

        // for visualization
        float screen_width, screen_height;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    bool userPresent, normalizeWeight;
    float maxWeight = 0.0f;
};
