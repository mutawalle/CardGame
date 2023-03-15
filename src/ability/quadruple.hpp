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
        cout<< gameState.players.at(gameState.order.at(this->gameState.turn)).getName() << " melakukan QUADRUPLE"<<endl;
        cout<< "point naik dari " << gameState.point;
        this->gameState.point*=4;
        cout<< " menjadi " << gameState.point<< endl;
        this->gameState.turn++;
        this->gameState.turn %= 7;
    }
};

#endif