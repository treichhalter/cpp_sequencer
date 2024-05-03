#include "Sequencer.h"

Sequencer::Sequencer() : currentFunctionIndex(0), isLastFunction(false) {}

void Sequencer::addFunction(std::function<void(Sequencer&)> func) {
    functions.push_back(func);
}

void Sequencer::execute() {
    isLastFunction = (currentFunctionIndex == functions.size() - 1);

    functions[currentFunctionIndex](*this);
}

void Sequencer::step() {
    currentFunctionIndex = (currentFunctionIndex + 1) % functions.size();    
}

void Sequencer::skip(int numFunctionsToSkip) {
    currentFunctionIndex = (currentFunctionIndex + numFunctionsToSkip) % functions.size();
}

bool Sequencer::isLast() const {
    return isLastFunction;
}