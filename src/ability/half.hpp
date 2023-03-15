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
        cout<< gameState.players.at(gameState.order.at(this->gameState.turn)).getName() << " melakukan HALF"<<endl;
        if(this->gameState.point>1){
            cout<< "point turun dari " << gameState.point;
            this->gameState.point/=2;
            cout<< " menjadi " << gameState.point<< endl;
        }
        else if(this->gameState.point==1){
            cout << "Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut!"<<endl;
        }
        this->gameState.turn++;
        this->gameState.turn %= 7;
    }
};

#endif