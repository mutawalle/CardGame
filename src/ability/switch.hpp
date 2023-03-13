#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <iostream>

#include "action.hpp"

using namespace std;

class Switch : public Action {
protected:
    // Indeks pemain pada vector of pemain
    int firstPlayer;        
    int secondPlayer;
public:
    Switch() {}
    Switch (GameState gameState, int firstPlayer, int secondPlayer) : Action(gameState) {
        this->firstPlayer = firstPlayer;
        this->secondPlayer = secondPlayer;
    }
    void DoAction() {
        vector<Card> cl1 = this->gameState.players.at(firstPlayer).getPlayerCard().getCard();
        vector<Card> cl2 = this->gameState.players.at(secondPlayer).getPlayerCard().getCard();
        vector<Card> temp = cl1;
        cl1 = cl2;
        cl2 = temp;
    }
};

#endif