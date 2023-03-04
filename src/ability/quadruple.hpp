#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include <iostream>
#include "action.hpp"
#include "next.hpp"
using namespace std;

class Quadruple : public Action {
public:
    Quadruple() {}
    Quadruple (GameState gameState) : Action(gameState) {}
    void DoAction() {
        // int point = gameState.GetPoint();
        // gameState.SetPoint(point * 4);
        // int index = gameState.GetIndex();
        // gameState.SetIndex(index + 1);
    }
};

#endif
