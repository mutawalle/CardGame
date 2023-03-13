#ifndef REVERSE_DIRECTION_HPP
#define REVERSE_DIRECTION_HPP

#include <algorithm>
#include <iostream>
#include "action.hpp"

using namespace std;

class ReverseDirection : public Action {
public:
    ReverseDirection() {}
    ReverseDirection (GameState gameState) : Action(gameState) {}
    void DoAction() {
        vector<int> order = this->gameState.order;
        for(int i=0;i<7;i++){
            reverse(order.begin(), order.end());
        }
        this->gameState.order = order;
        this->gameState.turn++;
    }
};

#endif
