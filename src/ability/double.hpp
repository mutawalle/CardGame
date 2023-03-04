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
        // int point = gameState.GetPoint();
        // gameState.SetPoint(point * 2);
        // int index = gameState.GetIndex();
        // gameState.SetIndex(index + 1);
    }
};

#endif