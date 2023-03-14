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
        if(this->gameState.point>1){
            this->gameState.point/=2;
        }
        this->gameState.turn++;
        this->gameState.turn %= 7;
    }
};

#endif