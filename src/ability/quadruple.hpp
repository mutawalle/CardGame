#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include <iostream>
#include "action.hpp"
using namespace std;

class Quadruple : public Action {
public:
    Quadruple() {}
    Quadruple (GameState gameState) : Action(gameState) {}
    void DoAction() {
        cout << "Quadruple" << endl;
    }
};

#endif
