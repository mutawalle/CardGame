#ifndef GAME_H
#define GAME_H

#include <cmath>
#include <vector>
#include <string>

#include "gameState.hpp"
#include "../command/command.hpp"
#include "../enum/abilities.hpp"

using namespace std;

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
                roundth();
                this->round++;
            }
        }

        void splitCards(){
            int j = 0;
            for(int i=52;i>38;i--){
                int randVal = rand() % i;
                vector<Card> pCards = gameState.players[j%7].getPlayerCard().getCard();
                vector<Card> dCards = gameState.deckCard.getCard();

                pCards.insert(pCards.end(), gameState.deckCard.getCard()[randVal]);
                dCards.erase(dCards.begin() + randVal);
                j++;
            }
        }

        void splitAbilities(){
            vector<string> listAbility = abilities;
            for(int i=7;i>0;i--){
                int randVal = rand() % i;
                gameState.players[8-i].getAbility() = listAbility[randVal];
                listAbility.erase(listAbility.begin() + randVal);
            }
        }

        void addTableCard(){
            int lenDC = gameState.deckCard.getCardListLength();
            int randVal = rand() % lenDC;
            vector<Card> tableCard = gameState.tableCard.getCard();
            vector<Card> deckCard = gameState.deckCard.getCard();

            tableCard.insert(tableCard.end(), deckCard.at(randVal));
            deckCard.erase(deckCard.begin() + randVal);
        }

        void roundth(){
            if(this->round==1){
                splitCards();
            }else if(this->round==2){
                splitAbilities();
            }
            if(this->round<6){
                addTableCard();
            }
            for(int i=0;i<7;i++){
                Command command = Command(gameState);
                command.inputCommand();
                command.abillityValidation();
                this->gameState = command.getGamestate();
            }

            if(this->round == 6){
                int winner6Idx=0;
                for(int i=0;i<7;i++){
                    if(this->gameState.players.at(i).value() > this->gameState.players.at(winner6Idx).value()){
                        winner6Idx = i;
                    }
                }

                this->gameState.players.at(winner6Idx).setPoint(this->gameState.players.at(winner6Idx).getPoint() + this->gameState.point);

                int winnerAllIdx = 0;
                for(int i=0;i<7;i++){
                    if(this->gameState.players.at(i).getPoint() > this->gameState.players.at(winnerAllIdx).getPoint()){
                        winnerAllIdx = i;
                    }
                }

                if(this->gameState.players.at(winnerAllIdx).getPoint() >= pow(2,32)){
                    this->isFinish = true;
                }else{
                    for(int i=0;i<7;i++){
                        this->gameState.players.at(i).setPlayerCard({});
                        this->gameState.players.at(i).setAbility("");
                    }
                    this->gameState.tableCard = TableCard();
                    this->gameState.deckCard = DeckCard();
                    this->gameState.point = 64;
                    this->gameState.order = {0,1,2,3,4,5,6};
                    this->gameState.turn = 0;
                }
            }else{

            }
        }
};

#endif