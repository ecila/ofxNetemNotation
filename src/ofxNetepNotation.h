#include "ofMain.h"

struct scoreEvent {
    float time;
};

struct note : public scoreEvent {
    float length;
    bool accented;
};

struct rest : public scoreEvent {
    float length;
};

enum annotationSymbols {CRESCENDO, FORTE};

struct annotationSymbol : public scoreEvent {
    int type;
};

struct annotationText : public scoreEvent {
    string text;
};

struct bar {
    vector<scoreEvent> events;
    int key;
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
};