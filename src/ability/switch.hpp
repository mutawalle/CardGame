#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <iostream>

#include "action.hpp"

using namespace std;

class Switch : public Action {
public:
    Switch() {}
    Switch (GameState gameState) : Action(gameState) {}
    void DoAction() {
        cout << "Switch" << endl;
    }
};

#endif