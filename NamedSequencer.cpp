#include <iostream>
#include "NamedSequencer.h"

void NamedSequencer::addFunction(const std::string& name, std::function<void(Sequencer&)> func) {
    Sequencer::addFunction(func);
    functionIndices[name] = functions.size() - 1;
}

void NamedSequencer::executeNamed(const std::string& name) {
    if (functionIndices.find(name) != functionIndices.end()) {
        currentFunctionIndex = functionIndices[name];
        execute();
    } else {
        std::cout << "Function with name " << name << " not found." << std::endl;
    }
}