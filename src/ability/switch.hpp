#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <iostream>

#include "action.hpp"
#include "../card/playerCard.hpp"

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
        PlayerCard cl1 = this->gameState.players.at(this->gameState.order.at(this->gameState.turn)).getPlayerCard();
        PlayerCard cl2 = this->gameState.players.at(this->target).getPlayerCard();
        this->gameState.players.at(this->target).setPlayerCard(cl1);
        this->gameState.players.at(this->gameState.order.at(this->gameState.turn)).setPlayerCard(cl2);
        cout << "Kartu telah ditukar, kamu mendapat kartu: " << endl;
        cout << this->gameState.players.at(this->gameState.order.at(this->gameState.turn)).getPlayerCard();
        this->gameState.turn++;
        this->gameState.turn %= 7;
    }
};

#endif