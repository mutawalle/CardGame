#ifndef RE_ROLL_HPP
#define RE_ROLL_HPP

#include <iostream>
#include "action.hpp"
#include "../player/player.hpp"

using namespace std;

class ReRoll : public Action {
public:
    ReRoll() {}
    ReRoll (GameState gameState) : Action(gameState) {}
    void DoAction() {
        // int index = gameState.GetIndex();
        // Player player = gameState.GetPlayer(index);
        // masih bingung cara membuang kartu dari player 
        // dan mengambil kartu baru dari deck
    }
};

#endif