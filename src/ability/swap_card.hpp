#ifndef SWAP_CARD_HPP
#define SWAP_CARD_HPP

#include <iostream>

#include "action.hpp"

using namespace std;

class SwapCard : public Action {
    int firstPlayer;
    int secondPlayer;
    int cardFirst;
    int cardSecond;
public:
    SwapCard() {}
    SwapCard (GameState gameState, int firstPlayer, int secondPlayer, int cardFirst, int cardSecond) : Action(gameState) {
        this->firstPlayer = firstPlayer;
        this->secondPlayer = secondPlayer;
        this->cardFirst = cardFirst;
        this->cardSecond = cardSecond;
    }
    void DoAction() {
        vector<Player> players = this->gameState.players;
        vector<Card> playerCard1 = this->gameState.players.at(firstPlayer).getPlayerCard();
        vector<Card> playerCard2 = this->gameState.players.at(secondPlayer).getPlayerCard();
    }
};

#endif