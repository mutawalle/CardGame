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
        // int point = gameState.GetPoint();
        // gameState.SetPoint(point / 4);
        // int index = gameState.GetIndex();
        // gameState.SetIndex(index + 1);

    }
};

#endif