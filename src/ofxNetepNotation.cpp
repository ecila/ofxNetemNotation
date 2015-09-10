#include "ofxNetepNotation.h"
#include <sstream>
#include <cmath>

void ofxNetepNotation::setup() {
    ofSetFrameRate(30);
    
    //pitchspacing
    int j=0;
    for(int i=0; i < 128; i++) {
        pitchSizes[i] = !(j==1 || j==3 || j==6 || j==8 || j==10);
        j++;
        if (j==12) {
            j=0;
        }
    }
    
    cout << (font.load("sonata.ttf", 64, true, true, true) ? "Font loaded ok" : "Error loading font") << endl;
    
    //create some random notes for testing
    scr.tempo = 128.4;
    scr.tempoDescription = "Vivace";
    scr.title = "Beethoven's 10th Symphony";
    bar *bar;
    bar = new struct bar();
    bar->clef = clefs::TREBLE;
    bar->key = 0;
    bar->timeDenominator=4;
    bar->timeNumerator = 4;

    note *n;
    n = new struct note();
    n->length=1;
    n->time=0;
    n->pitch=72;
    n->stemDirection = stemDirections::STEM_UP;
    bar->events.push_back(n);
    n = new struct note();
    n->length=1;
    n->time=1;
    n->pitch=68;
    n->stemDirection = stemDirections::STEM_DOWN;
    bar->events.push_back(n);
    n = new struct note();
    n->length=2;
    n->time=2;
    n->pitch=72;
    n->stemDirection = stemDirections::STEM_DOWN;
    bar->events.push_back(n);
    
    scr.bars.push_back(bar);

    bar = new struct bar();
    bar->clef = clefs::TREBLE;
    bar->key = 0;
    bar->timeDenominator=4;
    bar->timeNumerator = 4;
    
    n = new struct note();
    n->length=1;
    n->time=0;
    n->pitch=62;
    n->stemDirection = stemDirections::STEM_UP;
    bar->events.push_back(n);
    n = new struct note();
    n->length=2;
    n->time=1;
    n->pitch=65;
    n->stemDirection = stemDirections::STEM_DOWN;
    bar->events.push_back(n);
    n = new struct note();
    n->length=1;
    n->time=3;
    n->pitch=74;
    n->stemDirection = stemDirections::STEM_DOWN;
    bar->events.push_back(n);
    
    scr.bars.push_back(bar);

    
    stavex = 30;
    stavey = 100;
    stavew = 900;
    staveh = 100;
    
//    font.setup("sonata.ttf", 1.0, 1024, true, 8, 1.0);
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
//    bravura.drawString("\u00CE", 10,50);
//    font.draw("\u00CE", 60, 100, 100);
    //draw a stave
    for(int i=0; i <5; i++) {
        float y = stavey + (i*staveh/4);
        ofDrawLine(stavex, y, stavex + stavew, y);
    }
    
    //clef
    font.drawString("\u0026", stavex + 10, stavey + staveh - (staveh * 0.1));
    
    //timesig
    stringstream s;
    s << scr.bars[0]->timeDenominator;
    font.drawString(s.str(), stavex + 10 + font.stringWidth("\u0026") + 10, stavey + (staveh * 0.3));  //sort out positioning
    s.str("");
    s << scr.bars[0]->timeNumerator;
    font.drawString(s.str(), stavex + 10 + font.stringWidth("\u0026") + 10, stavey + (staveh * 0.7));  //sort out positioning
    
    float barWidth = 300;
    //notes
    for(int bar=0; bar < scr.bars.size(); bar++) {
        float barStart = font.stringWidth("\u0026") + font.stringWidth("0") + 60 + (bar * barWidth);
        
        for(int event=0; event < scr.bars[bar]->events.size(); event++) {
            if (scr.bars[bar]->events[event]->eventType == scoreEvent::scoreEventTypes::NOTE) {
                note *n = (note*) scr.bars[bar]->events[event];
                cout << n->pitch << endl;
                //which symbol?
                string noteSymbol = "";
                if (n->length==1) {
                    if (n->stemDirection == stemDirections::STEM_UP) {
                        noteSymbol = "q";
                    }else{
                        noteSymbol = "Q";
                    }
                }else if (n->length==2) {
                    if (n->stemDirection == stemDirections::STEM_UP) {
                        noteSymbol = "h";
                    }else{
                        noteSymbol = "H";
                    }
                }
                int lowerNote=0;
                switch(scr.bars[bar]->clef) {
                    case clefs::TREBLE:
                        lowerNote=64;
                        break;
                    case clefs::BASS:
                        lowerNote=42;
                        break;
                    case clefs::ALTO:
                        lowerNote=52;
                        break;
                    case clefs::TENOR:
                        lowerNote=50;
                        break;
                }
                float pitchHeight = staveh / 8;
                float pitchOffset=0;
                float pitchDir=1;
                if (n->pitch > lowerNote) {
                    for(int p=lowerNote+1; p <= n->pitch; p++) {
                        if (pitchSizes[p]) pitchOffset++;
                    }
                }else{
                    for(int p=lowerNote-1; p >= n->pitch; p--) {
                        if (pitchSizes[p]) pitchOffset++;
                    }
                    pitchDir = -1;
                }
                float notePosition = stavey + staveh - ((pitchOffset * pitchHeight));
                float notex = stavex + barStart + (n->time * barWidth / scr.bars[bar]->timeNumerator);
                font.drawString(noteSymbol, notex, notePosition);
                
            }
        }
        //draw separator
        float barLineX = stavex + barStart + (barWidth);
        ofDrawLine(barLineX, stavey, barLineX, stavey + staveh);
        
    };
    
    
}