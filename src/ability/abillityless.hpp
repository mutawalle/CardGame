#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "action.hpp"

using namespace std;

class AbilityLess : public Action {
    int targetPlayer;
public:
    AbilityLess() {}
    AbilityLess (GameState gameState, int targetPlayer) : Action(gameState) {
        this->targetPlayer = targetPlayer;
    }
    void DoAction() {
        this->gameState.players.at(this->targetPlayer).setAbilityLess(true);
        this->gameState.turn++;
        this->gameState.turn %= 7;
        cout << "kartu ability milik" << this->gameState.players.at(this->targetPlayer).getName() << " telah dimatikan" << endl;
    }
};

#endif