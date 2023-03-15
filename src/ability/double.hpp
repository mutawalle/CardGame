#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include <iostream>
#include "action.hpp"

using namespace std;

class Double : public Action {
public:
    Double() {}
    Double (GameState gameState) : Action(gameState) {}
    void DoAction() {
        this->gameState.point*=2;
        this->gameState.turn++;
        this->gameState.turn %= 7;
    }
};

#endif