#ifndef HALF_HPP
#define HALF_HPP

#include <iostream>
#include "action.hpp"

using namespace std;

class Half : public Action {
public:
    Half() {}
    Half (GameState gameState) : Action(gameState) {}
    void DoAction() {
        cout << "Half" << endl;
    }
};

#endif