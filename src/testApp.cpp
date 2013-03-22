#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetCircleResolution(150);
    
    updateInterval = 1;
    lastUpdated = -updateInterval;
}

//--------------------------------------------------------------
void testApp::update(){
    if(ofGetElapsedTimef()-lastUpdated > updateInterval){
        
        // Cosm API: http://cosm.com/docs/
        string feedno = "";
        string apikey = "";
        string url = "http://api.cosm.com/v2/feeds/"+feedno+".json?key="+apikey;
        //change the number in url to your cosm feed no. and API key
        
        // Now parse the JSON
        parsed = json.open(url);
        if ( parsed )
        {
            cout << json.getRawString() << endl;
            lastUpdated = ofGetElapsedTimef();
        }
        else
        {
            cout  << "Failed to parse JSON" << endl;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
//    ofColor dark(80);
//    ofBackgroundGradient(dark, ofColor::black);
    
    if(parsed)
    {
        ofxJSONElement datastreams = json["datastreams"];
        for(int i=0; i<datastreams.size(); i++)
        {
            cosmId = datastreams[i]["id"].asString();
            current_value = datastreams[i]["current_value"].asString();
            

            cosmId = ofxJSONElement::decodeURL( cosmId );
            ofDrawBitmapStringHighlight(cosmId + " = " + current_value, 10, 40*i+40);
        }
    }
    
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, ofToInt(current_value));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}