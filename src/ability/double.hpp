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
        cout << "Double" << endl;
    }
};

#endif