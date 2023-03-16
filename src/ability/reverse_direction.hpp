#ifndef REVERSE_DIRECTION_HPP
#define REVERSE_DIRECTION_HPP

#include <algorithm>
#include <iostream>
#include "action.hpp"

using namespace std;

class ReverseDirection : public Action {
public:
    ReverseDirection() {}
    ReverseDirection (GameState gameState) : Action(gameState) {}
    void DoAction() {
        vector<int> order = this->gameState.order;
        cout << "sebelum" << endl;
        for(int i=0;i<7;i++){
            cout << this->gameState.players.at(order.at(i)).getName() << " ";
        }
        cout << endl;
        for(int i=0;i<7;i++){
            reverse(order.begin(), order.end());
        }
        this->gameState.order = order;
        this->gameState.turn = 0;
        cout << "sesudah" << endl;
        for(int i=0;i<7;i++){
            cout << this->gameState.players.at(order.at(i)).getName() << " ";
        }
        cout << endl;
    }
};

#endif
