#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include <iostream>
#include "action.hpp"
#include "next.hpp"
using namespace std;

class Quadruple : public Action {
public:
    Quadruple() {}
    Quadruple (GameState gameState) : Action(gameState) {}
    void DoAction() {
        this->gameState.point*=4;
        this->gameState.turn++;
    }
};

#endif
