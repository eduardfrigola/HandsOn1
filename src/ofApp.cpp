#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    buttonWidth=200;
    buttonHeight=100;
    
    buttonPosition.x=ofGetWidth()/2-buttonWidth/2;
    buttonPosition.y=ofGetHeight()/1.15-buttonHeight/2;
    
    buttonColor.r=0;
    buttonColor.g=0;
    buttonColor.b=100;
    
    bike.loadImage("bike_no_pedals.png");
    
    bodyColor=ofColor(239, 200, 200);
    
    beginX=170;
    endX=ofGetWidth()-350;
    bikerOrigin=ofPoint(beginX, ofGetHeight()/2);
    
    kneeLPosition=ofPoint(bikerOrigin.x+70,bikerOrigin.y);
    kneeRPosition=ofPoint(bikerOrigin.x+70,bikerOrigin.y);
    
    pedalRadius=34;
    
    zerotopi=0;
    
    play=false;
    stopstate=true;
    speed=0;
    
    trafficLightPos=ofPoint(ofGetWidth()-124, 20);
    redLightColor=ofColor(255,0,0,255);
    orangeLightColor=ofColor(255,145,0, 50);
    greenLightColor=ofColor(0,255,0, 50);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //variables that have to update
    kneeLPosition.x=bikerOrigin.x+70;
    kneeRPosition.x=bikerOrigin.x+70;
    pedalierCenter=ofPoint(bikerOrigin.x+67, bikerOrigin.y+92);
    
    
    //Set and reset initial state
    if (stopstate==true){
        bikerOrigin=ofPoint(170, ofGetHeight()/2);
        zerotopi=0;
        
        pedalierCenter=ofPoint(bikerOrigin.x+67, bikerOrigin.y+92);
        pedalRPosition.x=pedalRadius*cos(zerotopi)+pedalierCenter.x;
        pedalRPosition.y=pedalRadius*sin(zerotopi)+pedalierCenter.y;
        
        pedalLPosition.x=-pedalRadius*cos(zerotopi)+pedalierCenter.x;
        pedalLPosition.y=-pedalRadius*sin(zerotopi)+pedalierCenter.y;
        
        kneeLPosition=ofPoint(bikerOrigin.x+70,bikerOrigin.y);
        kneeRPosition=ofPoint(bikerOrigin.x+70,bikerOrigin.y);
        speed=0;
        stopstate=false; //only has to run one time;
        orangeLightColor.a=50;
        redLightColor.a=255;
        greenLightColor.a=50;
    }
    
    
    
    //forward movement
    if(bikerOrigin.x<=endX && play==true){
        redLightColor.a=50;
        orangeLightColor.a=50;
        greenLightColor.a=255;
        bikerOrigin.x+=speed;
        speed+=0.05;
        zerotopi+=0.05;
        if (zerotopi>=2*PI){
            zerotopi=0;
        }
        pedalRPosition.x=pedalRadius*cos(zerotopi)+pedalierCenter.x;
        pedalRPosition.y=pedalRadius*sin(zerotopi)+pedalierCenter.y;
    
        pedalLPosition.x=-pedalRadius*cos(zerotopi)+pedalierCenter.x;
        pedalLPosition.y=-pedalRadius*sin(zerotopi)+pedalierCenter.y;
    
        kneeRPosition.y+=cos(zerotopi);
        kneeLPosition.y+=-cos(zerotopi);
    }
    
    
    if(bikerOrigin.x>=endX-200){
        greenLightColor.a=50;
        orangeLightColor.a=255;
    }
    if(bikerOrigin.x>=endX){
        orangeLightColor.a=50;
        redLightColor.a=255;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapString("Speed: "+ofToString(speed), ofPoint(5,20));
    ofDrawBitmapString("px/frame", ofPoint(120, 20));
    
    ofSetColor(0);
    ofRect(trafficLightPos.x, trafficLightPos.y, 80, 220);
    ofSetColor(redLightColor);
    ofCircle(trafficLightPos.x+40, trafficLightPos.y+40, 30);
    ofSetColor(orangeLightColor);
    ofCircle(trafficLightPos.x+40, trafficLightPos.y+110, 30);
    ofSetColor(greenLightColor);
    ofCircle(trafficLightPos.x+40, trafficLightPos.y+180, 30);
    
    
    //widht of lines
    ofSetLineWidth(12);
    
    
    //floor
    ofSetColor(0);
    ofRect(0, 555, ofGetWidth(),10);


    //leftarm
    ofSetColor(bodyColor.r+30, bodyColor.g, bodyColor.b);
    ofLine(bikerOrigin.x, bikerOrigin.y-240, bikerOrigin.x+125, bikerOrigin.y-140);
    
    //right hand
    ofCircle(bikerOrigin.x+125, bikerOrigin.y-140, 10);
    
    //left cuixa
    ofLine(ofPoint(bikerOrigin.x, bikerOrigin.y-100), kneeLPosition);
   
    
    //right cama
    ofLine(kneeLPosition, pedalLPosition);
    
    //draw pedal arm
    ofSetColor(70);
    ofLine(pedalierCenter, pedalLPosition);
    
    
    //knee joint
    ofSetColor(bodyColor.r+30, bodyColor.g, bodyColor.b);
    ofCircle(kneeLPosition, 7);
    
    //draw pedal
    ofSetColor(255, 0, 0);
    ofRect(pedalLPosition.x-10, pedalLPosition.y-2.5, 20, 5);

    //bike
    ofSetColor(255);
    bike.draw(bikerOrigin.x-bike.width/2+90, bikerOrigin.y-bike.height/2+20);
    
    //---------------------------------------------------------------------------------------------
    //things draw top of bike
    
    //body and head
    ofSetColor(bodyColor.r+60, bodyColor.g, bodyColor.b);
    ofCircle(bikerOrigin.x, bikerOrigin.y-300, 30);
    ofEllipse(bikerOrigin.x, bikerOrigin.y-170, 100, 200);
    
    //right arm
    ofSetColor(bodyColor);
    ofLine(bikerOrigin.x, bikerOrigin.y-240, bikerOrigin.x+120, bikerOrigin.y-135);
    
    //arm joint
    ofCircle(bikerOrigin.x, bikerOrigin.y-240, 10);
    
    //right hand
    ofCircle(bikerOrigin.x+120, bikerOrigin.y-135, 10);
    
    //right cuixa
    ofLine(ofPoint(bikerOrigin.x, bikerOrigin.y-100), kneeRPosition);
    
    //pelvis
    ofCircle(bikerOrigin.x, bikerOrigin.y-100, 12);
    
    //draw pedal arm
    ofSetColor(70);
    ofLine(pedalierCenter, pedalRPosition);
    
    //center of pedalier
    ofCircle(pedalierCenter, 9);
    
    //right cama
    ofSetColor(bodyColor);
    ofLine(kneeRPosition, pedalRPosition);
    
    //knee joint
    ofCircle(kneeRPosition, 7);
    
    //draw pedal
    ofSetColor(255, 0, 0);
    ofRect(pedalRPosition.x-10, pedalRPosition.y-2.5, 20, 5);

    
    //draw button
    ofSetColor(buttonColor);
    ofRect(buttonPosition,buttonWidth,buttonHeight);
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    play=false;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    play=true;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mousePosition.x=x;
    mousePosition.y=y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    if(ofInRange(x, buttonPosition.x, buttonPosition.x+buttonWidth) && ofInRange(y, buttonPosition.y, buttonPosition.y+buttonHeight))
    {
        buttonColor = ofColor(0,255,0);
    }
    
    stopstate=true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  //prova
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
//prova2
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
