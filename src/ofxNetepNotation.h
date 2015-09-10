#include "ofMain.h"
#include "ofxFontStash.h"

#ifndef uint
#define uint unsigned int
#endif


struct scoreEvent {
    float time;
};

enum noteAnnotations {STACCATO, ACCENT};
enum accidentals {FLAT, SHARP, DOUBLEFLAT, DOUBLESHARP};

struct note : public scoreEvent {
    float length;
    vector<noteAnnotations> annotations;
    accidentals accidental;
};

struct rest : public scoreEvent {
    float length;
};

enum annotationSymbols {CRESCENDO, FORTE};

struct annotationSymbol : public scoreEvent {
    int type;
};

struct slur : public annotationSymbol {
    note *start, *end;
};


struct annotationText : public scoreEvent {
    string text;
};

enum clefs {TREBLE, BASS, ALTO, TENOR};

struct bar {
    vector<scoreEvent> events;
    int key;
    //time sig
    unsigned int timeNumerator, timeDenominator;
    clefs clef;
    
};

struct score {
    vector<bar> bars;
    float tempo;
    std::string title;
};

class ofxNetepNotation {
public:
    
    ofTrueTypeFont bravura;

    void setup();
    void render();
    
    score scr;
    
    ofxFontStash font;
    ofxFontStash unicodeFont;

};