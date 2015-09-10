#include "ofMain.h"
#include "ofxFontStash.h"

#ifndef uint
#define uint unsigned int
#endif


struct scoreEvent {
    enum scoreEventTypes {NOTE, REST, SYMBOL, SLUR, TEXT};
    scoreEvent(scoreEventTypes scoreEventType) : eventType(scoreEventType) {}
    scoreEventTypes eventType;
    float time;
};

enum noteAnnotations {STACCATO, ACCENT};
enum accidentals {FLAT, SHARP, DOUBLEFLAT, DOUBLESHARP};
enum stemDirections {STEM_UP, STEM_DOWN};

struct note : public scoreEvent {
    note() : scoreEvent(scoreEvent::scoreEventTypes::NOTE) {}
    float length;
    int pitch;
    vector<noteAnnotations> annotations;
    accidentals accidental;
    stemDirections stemDirection;
};

struct rest : public scoreEvent {
    rest() : scoreEvent(scoreEvent::scoreEventTypes::REST) {}
    float length;
};

enum annotationSymbols {CRESCENDO, FORTE};

struct annotationSymbol : public scoreEvent {
    annotationSymbol() : scoreEvent(scoreEvent::scoreEventTypes::SYMBOL) {}
    int type;
};

struct slur : public scoreEvent {
    slur() : scoreEvent(scoreEvent::scoreEventTypes::SLUR) {}
    note *start, *end;
};


struct annotationText : public scoreEvent {
    annotationText() : scoreEvent(scoreEvent::scoreEventTypes::TEXT) {}
    string text;
};

enum clefs {TREBLE, BASS, ALTO, TENOR};

struct bar {
    vector<scoreEvent*> events;
    int key;
    //time sig
    unsigned int timeNumerator, timeDenominator;
    clefs clef;    
};

struct score {
    vector<bar*> bars;
    float tempo;
    std::string tempoDescription;
    std::string title;
    std::string composer;
};

class ofxNetepNotation {
public:
    
    ofTrueTypeFont font;

    void setup();
    void render();
    
    score scr;
    
    //do we need this?
//    ofxFontStash font;
//    ofxFontStash unicodeFont;
private:
    float stavex, stavey, staveh, stavew;
    bool pitchSizes[128];

};