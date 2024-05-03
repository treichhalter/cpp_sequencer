#pragma once

#include <vector>
#include <functional>

class Sequencer {
protected:
    std::vector<std::function<void(Sequencer&)>> functions;
    int currentFunctionIndex;
    bool isLastFunction;

public:
    Sequencer();

    void addFunction(std::function<void(Sequencer&)> func);

    void execute();

    void step();

    void skip(int numFunctionsToSkip);

    bool isLast() const;
};
