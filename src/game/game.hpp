#ifndef GAME_H
#define GAME_H

#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <time.h>

#include "gameState.hpp"
#include "../command/command.hpp"


vector<string> abilities = {"RE-ROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH", "ABILITYLESS"};

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
            Command command(this->gameState);
            command.chooseSplitingCard();
            command.inputName();
            this->gameState = command.getGamestate();

            while(!isFinish){
                command.splashRound(this->round);
                roundth();
                this->roundRobin();
                this->round++;
            }
            
        }

        void splitCards(){
            for(int i=0;i<14;i++){
                PlayerCard playerCard = this->gameState.players.at((int) i/2).getPlayerCard();
                vector<Card> deckCards = this->gameState.deckCard.getCard();

                playerCard + deckCards.at(i);
                deckCards.erase(deckCards.begin());

                this->gameState.players.at((int) i/2).setPlayerCard(playerCard);
                this->gameState.deckCard.setCard(deckCards);
            }
        }

        void splitAbilities(){
            for(int i=7;i>0;i--){
                srand(time(nullptr));
                int randVal = rand() % i;
                gameState.players[7-i].setAbility(abilities[randVal]);
                abilities.erase(abilities.begin() + randVal);
            }
        }

        void addTableCard(){
            int lenDC = gameState.deckCard.getCardListLength();
            int randVal = rand() % lenDC;
            Card tmp = this->gameState.deckCard.getCard().at(randVal);

            this->gameState.tableCard + tmp;
            this->gameState.deckCard - tmp;
        }

        void roundRobin(){
            this->gameState.order.insert(this->gameState.order.end(), this->gameState.order.at(0));
            this->gameState.order.erase(this->gameState.order.begin());
        }

        void roundth(){
            if(this->round==1){
                splitCards();
            }else if(this->round==2 && this->gameState.players.at(0).getAbility() == ""){
                splitAbilities();
            }
            if(this->round<6){
                addTableCard();
            }
            for(int i=0;i<7;i++){
                Command command = Command(gameState);
                command.inputCommand();
                this->gameState = command.getGamestate();
                this->gameState.printState();
            }

            if(this->round == 6){
                for(int i=0;i<7;i++){
                    for(int j=0;j<5;j++){
                        PlayerCard playerCards = this->gameState.players.at(i).getPlayerCard();
                        playerCards + this->gameState.tableCard.getCard().at(j);
                        this->gameState.players.at(i).setPlayerCard(playerCards);
                    }
                }

                for(int i=0;i<7;i++){
                    this->gameState.players.at(i).setValue();
                }

                Player winner = getMax(this->gameState.players);
                cout << winner.getValue() << endl;

                int winnerIdx = distance(find(this->gameState.players.begin(), this->gameState.players.end(), winner), this->gameState.players.begin());

                this->gameState.players.at(winnerIdx).setPoint(this->gameState.players.at(winnerIdx).getPoint() + this->gameState.point);
                
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
                    this->round = 0;
                }
            }
            this->gameState.turn = 0;
        }

        template <class T>
        T getMax(vector<T>& listData){
            int len;
            len = listData.size();
            T max = listData.at(0);
            for(int i=1;i<len;i++){
                if(listData.at(i)>max){
                    max = listData.at(i);
                }
            }
            return max;
        }
};

#endif