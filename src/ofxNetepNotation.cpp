#include "ofxNetepNotation.h"

void ofxNetepNotation::setup() {
    cout << (bravura.load("sonata.ttf", 20) ? "Font loaded ok" : "Error loading font") << endl;
}

void ofxNetepNotation::render() {
    ofSetColor(0,0,0);
    bravura.drawString("ABCDEFGHIJKLMNOPQRSTUVWXYZabsdefghi", 100,100);
}