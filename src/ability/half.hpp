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
        // int point = gameState.GetPoint();
        // gameState.SetPoint(point / 2);
        // int index = gameState.GetIndex();
        // gameState.SetIndex(index + 1);
    }
};

#endif