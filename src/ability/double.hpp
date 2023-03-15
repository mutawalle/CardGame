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
        cout<< gameState.players.at(gameState.order.at(this->gameState.turn)).getName() << " melakukan DOUBLE"<<endl;
        cout<< "point naik dari " << gameState.point;
        this->gameState.point*=2;
        cout<< " menjadi " << gameState.point<< endl;
        this->gameState.turn++;
        this->gameState.turn %= 7;
    }
};

#endif