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
        vector<Card> playerCard1 = players.at(firstPlayer).getPlayerCard().getCard();
        vector<Card> playerCard2 = players.at(secondPlayer).getPlayerCard().getCard();
        Card tmp = playerCard1.at(cardFirst);

        playerCard1.erase(playerCard1.begin() + cardFirst);
        playerCard1.insert(playerCard1.begin() + cardFirst, playerCard2.at(cardSecond));
        playerCard2.erase(playerCard2.begin() + cardSecond);
        playerCard2.insert(playerCard2.begin() + cardSecond, tmp);
    }
};

#endif