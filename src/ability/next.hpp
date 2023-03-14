#ifndef NEXT_HPP
#define NEXT_HPP

#include <iostream>

#include "action.hpp"

using namespace std;

class Next : public Action {
public:
    Next() {}
    Next (GameState gameState) : Action(gameState) {}
    void DoAction() {
        this->gameState.turn++;
        this->gameState.turn %= 7;
    }
};

#endif
