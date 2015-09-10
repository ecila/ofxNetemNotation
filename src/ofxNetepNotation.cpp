#include "ofxNetepNotation.h"

void ofxNetepNotation::setup() {
    cout << (bravura.load("sonata.ttf", 20) ? "Font loaded ok" : "Error loading font") << endl;
    
    //create some random notes for testing
    scr.tempo = 128.4;
    scr.title = "Beethoven's 10th Symphony";
    bar *bar = new struct bar();
}

void ofxNetepNotation::render() {
    ofSetColor(0,0,0);
    bravura.drawString("ABCDEFGHIJKLMNOPQRSTUVWXYZabsdefghi", 100,100);
}