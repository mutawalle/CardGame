#ifndef REVERSE_DIRECTION_HPP
#define REVERSE_DIRECTION_HPP

#include <iostream>
#include "action.hpp"

using namespace std;

class ReverseDirection : public Action {
public:
    ReverseDirection() {}
    ReverseDirection (GameState gameState) : Action(gameState) {}
    void DoAction() {
        // cara tau arah sekarang bagaimana ?
    }
};

#endif
