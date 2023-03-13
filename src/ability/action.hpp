#ifndef ACTION_HPP
#define ACTION_HPP

#include <iostream>
#include "../game/gameState.hpp"

using namespace std;

class Action {
public:
    Action() {}
    Action (GameState gameState) {
        Action::gameState = gameState;
    }
    static GameState GetGameState() {
        return gameState;
    }
    static void SetGameState(GameState other) {
        Action::gameState = other;
    }
    virtual void DoAction() = 0;

protected:
    static GameState gameState;
};

GameState Action::gameState;

#endif