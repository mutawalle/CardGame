#ifndef SWAP_CARD_HPP
#define SWAP_CARD_HPP

#include <iostream>

#include "action.hpp"

using namespace std;

class SwapCard : public Action {
public:
    SwapCard() {}
    SwapCard (GameState gameState) : Action(gameState) {}
    void DoAction() {
        cout << "masukan pemain yang ingin ditukar kartunya: ";
        int player;
        cin >> player;
        
    }
};

#endif