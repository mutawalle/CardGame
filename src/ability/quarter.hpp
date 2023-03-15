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
        cout<< gameState.players.at(gameState.order.at(this->gameState.turn)).getName() << " melakukan QUARTER"<<endl;
        if(this->gameState.point>=4){
            cout<< "point turun dari " << gameState.point;
            this->gameState.point/=4;
            cout<< " menjadi " << gameState.point<< endl;
        }
        else if(this->gameState.point<4){
            cout << "Sayangnya poin hadiah bernilai kurang dari 4. Poin hadiah tidak berubah.. Giliran dilanjut!"<<endl;
        }
        this->gameState.turn++;
        this->gameState.turn %= 7;
    }
};

#endif