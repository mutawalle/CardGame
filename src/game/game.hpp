#ifndef GAME_H
#define GAME_H
#include "gameState.hpp"

#include <vector>
#include <string>

#include "../command/command.hpp"

using namespace std;

vector<string> abilities = {"re-roll", "quadruple", "quarter", "reverse", "swap", "switch", "abilityless"}; 

class Game {
    private:
        GameState gameState;
        int round;
        bool isFinish;
    public:
        Game(){
            this->gameState = GameState();
            this->round = 1;
            this->isFinish = false;
        }

        void start(){
            while(!isFinish){
                ronde();
            }
        }

        void splitCards(){
            int j = 1;
            for(i=52;i>38;i--){
                int randVal = rand() % i;
                gameState.players[j%7].cards.insert(gameState.deckCard[randVal]);
                gameState.deckCard.er
            }
        }

        void splitAbilities(){
            for(int i=7;i>0;i--){
                int randVal = rand() % i;
                gameState.players[8-i].ability = abilities[randVal];
                abilities.erase(randVal);
            }
        }

        void ronde(){
            if(this->round==1){
                splitCards();
            }else if(this->round==2){
                splitAbilities();
            }

            Command command;
            command.run();
        }
};

#endif