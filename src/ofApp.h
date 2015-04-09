#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    private:
        ofPoint mousePosition;
    
    ofPoint buttonPosition;
    int buttonWidth;
    int buttonHeight;
    ofColor buttonColor;
    
    ofColor bodyColor;
    
    ofPoint bikerOrigin;
    
    ofPoint kneeLPosition;
    ofPoint kneeRPosition;
    
    ofPoint pedalierCenter;
    ofPoint pedalLPosition;
    ofPoint pedalRPosition;
    int pedalRadius;
    float zerotopi;
    
    ofImage bike;
    
    bool stopstate;
    bool play;
    
    int beginX;
    int endX;
    
    float speed;
    
    ofColor redLightColor;
    ofColor greenLightColor;
    ofColor orangeLightColor;
    
    ofPoint trafficLightPos;
};
