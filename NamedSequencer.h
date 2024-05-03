#pragma once

#include "Sequencer.h"
#include <unordered_map>
#include <string>

class NamedSequencer : public Sequencer {
private:
    std::unordered_map<std::string, size_t> functionIndices;

public:    
    void addFunction(const std::string& name, std::function<void(Sequencer&)> func);

    void executeNamed(const std::string& name);
};