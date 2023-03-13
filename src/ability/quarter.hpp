#ifndef QUARTER_HPP
#define QUARTER_HPP

#include <iostream>

#include "action.hpp"

using namespace std;

class Quarter : public Action {
public:
    Quarter() {}
    Quarter (GameState gameState) : Action(gameState) {}
    void DoAction() {
        if(this->gameState.point>=4){
            this->gameState.point/=4;
        }
        this->gameState.turn++;
    }
};

#endif