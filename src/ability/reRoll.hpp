#ifndef RE_ROLL_HPP
#define RE_ROLL_HPP

#include <iostream>
#include <cmath>
#include "action.hpp"
#include "../player/player.hpp"

using namespace std;

class ReRoll : public Action {
public:
    ReRoll() {}
    ReRoll (GameState gameState) : Action(gameState) {}
    void DoAction() {
        cout << "Melakukan pembuangan kartu yang sedang dimiliki"<<endl;
        cout << "Kamu mendapatkan 2 kartu baru yaitu:"<< endl;
        vector<Card> playerCard = this->gameState.players.at(this->gameState.turn).getPlayerCard().getCard();
        vector<Card> deckCard = this->gameState.deckCard.getCard();
        playerCard.erase(playerCard.end());
        playerCard.erase(playerCard.begin());
        int lenDC = this->gameState.deckCard.getCardListLength();
        int randVal;
        for(int i=lenDC;i>(lenDC-2);i--){
            randVal = rand() % i;
            playerCard.insert(playerCard.end(), deckCard.at(randVal));
            deckCard.erase(deckCard.begin() + randVal);
        }
        this->gameState.deckCard = deckCard;
        this->gameState.players.at(this->gameState.turn).setPlayerCard(playerCard);
        this->gameState.turn++;
        this->gameState.turn %= 7;
        cout << this->gameState.players.at(this->gameState.order.at(this->gameState.turn)).getPlayerCard();
    }
};

#endif