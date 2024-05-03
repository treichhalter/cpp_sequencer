#include <iostream>
#include <string>
#include "Sequencer.h"
#include "NamedSequencer.h"

using namespace std;

void function4(Sequencer& sequencer) {
    cout << "Function 4\n";
}

int main() {

    Sequencer sequencer;    
    sequencer.addFunction([](Sequencer& sequencer) { cout << "Function 1\n"; sequencer.skip(1); });
    sequencer.addFunction([](Sequencer& sequencer) { cout << "Function 2\n"; });
    sequencer.addFunction([](Sequencer& sequencer) { cout << "Function 3\n"; sequencer.step(); });
    sequencer.addFunction(function4);

    sequencer.execute();
    sequencer.step();
    sequencer.execute();    
    sequencer.execute();
    sequencer.step();
    sequencer.isLast() ? cout << "Last function\n" : cout << "Not last function\n";
    sequencer.execute();
    sequencer.isLast() ? cout << "Last function\n" : cout << "Not last function\n";
    sequencer.execute();
    sequencer.isLast() ? cout << "Last function\n" : cout << "Not last function\n";


    NamedSequencer namedSequencer;    
    namedSequencer.addFunction("function1", [](Sequencer& sequencer) { cout << "Named Function 1\n"; });    
    namedSequencer.addFunction("function2", [](Sequencer& sequencer) { cout << "Named Function 2\n"; });
    namedSequencer.addFunction("function3", [](Sequencer& sequencer) { cout << "Named Function 3\n"; });
    namedSequencer.addFunction("function4", function4);

    namedSequencer.execute();
    namedSequencer.execute();
    namedSequencer.step();
    namedSequencer.execute();
    namedSequencer.executeNamed("function1");
    namedSequencer.executeNamed("function3");
    namedSequencer.step();
    namedSequencer.execute();    
    namedSequencer.isLast() ? cout << "Last function\n" : cout << "Not last function\n";

    return 0;
}