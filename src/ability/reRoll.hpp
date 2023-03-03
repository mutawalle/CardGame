#ifndef RE_ROLL_HPP
#define RE_ROLL_HPP

#include <iostream>
#include "action.hpp"

using namespace std;

class ReRoll : public Action {
public:
    ReRoll() {}
    ReRoll (GameState gameState) : Action(gameState) {}
    void DoAction() {
        cout << "ReRoll" << endl;
    }
};

#endif