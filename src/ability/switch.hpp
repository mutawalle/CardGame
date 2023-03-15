#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <iostream>

#include "action.hpp"

using namespace std;

class Switch : public Action {
protected:
    // Indeks pemain pada vector of pemain
    int target;        
public:
    Switch() {}
    Switch (GameState gameState, int target) : Action(gameState) {
        this->target = target;
    }
    void DoAction() {
        vector<Card> cl1 = this->gameState.players.at(this->gameState.order.at(this->gameState.turn)).getPlayerCard().getCard();
        vector<Card> cl2 = this->gameState.players.at(this->target).getPlayerCard().getCard();
        this->gameState.players.at(this->target).getPlayerCard().setCard(cl1);
        this->gameState.players.at(this->gameState.order.at(this->gameState.turn)).getPlayerCard().setCard(cl2);
        this->gameState.turn++;
        this->gameState.turn %= 7;
    }
};

#endif