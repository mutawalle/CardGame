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
        // int index = gameState.GetIndex();
        // gameState.SetIndex(index + 1);
    }
};

#endif
