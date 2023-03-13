#ifndef PLAYER_H
#define PLAYER_H

#include "../card/playerCard.hpp"
#include "../card/card.hpp"
#include <bits/stdc++.h>

using namespace std;

class Player {
    private:
        string name;
        PlayerCard playerCard;
        string ability;
        long long int poin;
    public:
        void bubbleSort() {
            for (int i = 0; i < playerCard.getCard().size() - 1; i++) {
                for (int j = 0; j < playerCard.getCard().size()- i - 1; j++) {
                    if (playerCard.getCard()[j].getNumber() > playerCard.getCard()[j+1].getNumber()) {
                        Card temp = playerCard.getCard()[j];
                        playerCard.getCard()[j] = playerCard.getCard()[j+1];
                        playerCard.getCard()[j+1] = temp;
                    }
                }
            }
        }

        PlayerCard getPlayerCard (){
            return playerCard;
        }

        void setPlayerCard(PlayerCard playerCard){
            this->playerCard = playerCard;
        }

        string getAbility(){
            return this->ability;
        }

        Card getHighCard (){
            Card card = playerCard.getCard()[0];
            for(int i = 1; i < playerCard.getCard().size(); i++){
                if(card.getValue() < playerCard.getCard()[i].getValue()){
                    card = playerCard.getCard()[i];
                }
            }
            return card;
        }
        vector<Card> PairCard (){
            int pairCount = 0;
            vector<Card> pair;
            for(int i = 0; i < playerCard.getCard().size() -1 ; i++){
                for(int j = i+1; j < playerCard.getCard().size(); j++){
                    if(playerCard.getCard()[i].getNumber() == playerCard.getCard()[j].getNumber()){
                        pairCount += 1;
                        pair.push_back(playerCard.getCard()[i]);
                        pair.push_back(playerCard.getCard()[j]);
                        break;
                    }
                }
            }
            return pair;
        }

        vector<Card> threeOfKind(){
            vector<Card> Three;
            int countThree = 0;
            for(int i = 0; i < playerCard.getCard().size() -1 ; i++){
                for(int j = i+1; j < playerCard.getCard().size(); j++){
                    if(playerCard.getCard()[i].getNumber() == playerCard.getCard()[j].getNumber()){
                        for(int k = j+1; k < playerCard.getCard().size(); k++){
                            if(playerCard.getCard()[i].getNumber() == playerCard.getCard()[k].getNumber()){
                                countThree ++;
                                Three.push_back(playerCard.getCard()[i]);
                                Three.push_back(playerCard.getCard()[j]);
                                Three.push_back(playerCard.getCard()[k]);
                                break;
                            }
                        }
                    }
                    if(countThree == 1){
                        break;
                    }
                }
                if(countThree == 1){
                    break;
                }
            }
            return Three;
        }

        vector<Card> straight (){
            // //vector sudah terurut
            // int index = 0;
            // vector<Card> straightVec;
            // for(int i = 0; i < playerCard.getCard().size(); i++){
            //     bool str = false;
            //     int count = 0;
            //     for(int j = i+1; j< playerCard.getCard().size(); j++){
            //         if(playerCard.getCard()[i].getNumber() - i == playerCard.getCard()[j].getNumber() - j){
            //             count ++;
            //         }
            //         if(count == 5){
            //             str = true;
            //             break;
            //         }
            //     }

            // }
            // if(str){
            //     for(int i = index; i<index+4; i++){
            //         straightVec.push_back(playerCard.getCard()[i]);
            //     }
            // }
            // return straightVec;
        }
        double value(){
            // if(isFullHouse){
            //     value = 
            // }
        }
};

#endif