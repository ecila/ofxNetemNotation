#include "ofxNetepNotation.h"
#include <sstream>

void ofxNetepNotation::setup() {
    cout << (bravura.load("sonata.ttf", 20, true, true, true) ? "Font loaded ok" : "Error loading font") << endl;
    
    //create some random notes for testing
    scr.tempo = 128.4;
    scr.title = "Beethoven's 10th Symphony";
    bar *bar = new struct bar();
    
    font.setup("sonata.ttf", 1.0, 1024, true, 8, 1.0);
//    font.addFont("VeraMono-Bold.ttf");
//    unicodeFont.setup("Arial Unicode.ttf", //font file, ttf only
//                      1.0,					//lineheight percent
//                      1024,					//texture atlas dimension
//                      true,					//create mipmaps of the font, useful to scale down the font at smaller sizes
//                      8,					//texture atlas element padding, shouldbe >0 if using mipmaps otherwise
//                      2.0f					//dpi scaleup, render textures @2x the reso
//                      );					//lower res mipmaps wil bleed into each other

}

void ofxNetepNotation::render() {
    ofSetColor(0,0,0);
    stringstream s;
    for(unsigned int i=0; i < 256; i++) {
        s << (unsigned char)i;
        if (i%64==0 && i > 0) {
            s << endl << endl;
        }
    }
//    bravura.drawString(s.str(), 10,10);
//    char test[255];
//    for(int i=0; i < 50; i++) {
//        test[i] = (char)i;
//    }
//    const wchar_t wtext[] = L"olé" ;
 
//    char x[10];
//    x[0] = (unsigned char) 206;
//    x[9]=0;
//    cout << "test: " << x << endl;
    bravura.drawString("\u00CE", 10,50);
//    font.draw("\u00CE", 60, 100, 100);
}