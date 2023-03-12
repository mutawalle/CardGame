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
        string abillity;
        long long int poin;
        // nama (string)
        // playerCard (PlayerCard)
        // ability (string) "" berarti tidak punya ability
        // poin
    public:
        Player(): playerCard(){
            name = "";
            abillity = "";
            poin = 0;
        }
        Player(string _name, PlayerCard pc, string _abillity, long long int _poin): playerCard(pc){
            name = _name;
            abillity = _abillity;
            poin = _poin;
        }
        Player(const Player& other): playerCard(other.playerCard){
            name = other.name;
            abillity = other.abillity;
            poin = other.poin;
        }
        // ~Player(){

        // }

        PlayerCard getPlayerCard (){
            return playerCard;
        }

        void bubbleSort() {
            for (int i = 0; i < playerCard.getCard().size() - 1; i++) {
                for (int j = 0; j < playerCard.getCard().size()- i - 1; j++) {
                    if (playerCard.getCard()[j].getValue() > playerCard.getCard()[j+1].getValue()) {
                        Card temp = playerCard.getCard()[j];
                        playerCard.getCard()[j] = playerCard.getCard()[j+1];
                        playerCard.getCard()[j+1] = temp;
                    }
                }
            }
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
            for(int i = playerCard.getCardListLength()-1; i>=2; i--){
                if(playerCard.getCard()[i].getNumber() == playerCard.getCard()[i-1].getNumber() && playerCard.getCard()[i].getNumber() == playerCard.getCard()[i-2].getNumber()){
                    Three.push_back(playerCard.getCard()[i]);
                    Three.push_back(playerCard.getCard()[i-1]);
                    Three.push_back(playerCard.getCard()[i-2]);
                    break;
                }
            }
            return Three;
        }

        vector<Card> straight (){
            //vector sudah terurut
            int index = 0;
            vector<Card> straightVec;
            bool str = false;
            for(int i = 0; i <= playerCard.getCard().size()-5; i++){
                int count = 1;
                for(int j = i+1; j < i+4; j++){
                    if(playerCard.getCard()[i].getNumber() - i == playerCard.getCard()[j].getNumber() - j){
                        count ++;
                    }
                    if(count == 5){
                        str = true;
                        index = i;
                        break;
                    }
                }
            }
            if(str){
                for(int i = index ; i<index+5; i++){
                    straightVec.push_back(playerCard.getCard()[i]);
                }
            }
            
            return straightVec;
        }

        vector<Card> Flush (){
            //Total kartu ada 7, jadi maksimal hanya ada 1 kombinasi flush
            bool isFlush = false;
            vector<Card> FlushCard;
            string color;
            for(int i = 0; i<playerCard.getCardListLength(); i++){
                int count = 0;
                for(int j = i+1; j < playerCard.getCardListLength(); j++){
                    if(playerCard.getCard()[i].getColor() == playerCard.getCard()[j].getColor()){
                        count ++;
                    }
                    if(count == 5){
                        isFlush = true;
                        color = playerCard.getCard()[i].getColor();
                    }
                }
            }
            if(isFlush){
                int i = playerCard.getCardListLength() - 1;
                //list sudah terurut, untuk memaksimalkan combo dipilih kartu dengan nilai paling besar
                while(FlushCard.size() < 5){
                    if(playerCard.getCard()[i].getColor() == color){
                        FlushCard.push_back(playerCard.getCard()[i]);
                    }
                    i--;
                }
            }
            return FlushCard;
        }
        
        vector<Card> FullHouse (){
            vector<Card> temp;
            int count2Card = 0;
            int number1 = 0;
            for(int i = playerCard.getCardListLength()-1; i>=2; i--){
                if(playerCard.getCard()[i].getNumber() == playerCard.getCard()[i-1].getNumber() && playerCard.getCard()[i].getNumber() == playerCard.getCard()[i-2].getNumber()){
                    number1 = playerCard.getCard()[i].getNumber();
                    break;
                }
            }
            if(number1 == 0){
                return temp;
            }
            else{
                for(int i = 0; i < playerCard.getCardListLength(); i++){
                    if(playerCard.getCard()[i].getNumber() == number1){
                        temp.push_back(playerCard.getCard()[i]);
                    }
                }

                for(int i = playerCard.getCardListLength()-1; i>=1; i--){
                    if(playerCard.getCard()[i].getNumber() == playerCard.getCard()[i-1].getNumber() && playerCard.getCard()[i].getNumber() != number1){
                        temp.push_back(playerCard.getCard()[i]);
                        temp.push_back(playerCard.getCard()[i-1]);
                        break;
                    }
                }
                if(temp.size() == 5){
                    return temp;
                }
                else{
                    return {};
                }
            }
            
        }

        vector<Card> FourOfKind (){
            vector<Card> FOKcard;
            for(int i = playerCard.getCardListLength()-1; i>= 3; i--){
                bool found = true;
                for(int j = 1; j < 4; j++){
                    if(playerCard.getCard()[i].getNumber() != playerCard.getCard()[i-j].getNumber()){
                        found = false;
                    }
                }
                if(found){
                    for(int k = i; k>=i-3; k--){
                        FOKcard.push_back(playerCard.getCard()[k]);
                    }
                    break;
                }
            }
            return FOKcard;
        }

        vector<Card> straightFlush(){
            vector<Card> SFCard;
            bool str = false;
            int index = 0;
            for(int i = 0; i <= playerCard.getCard().size()-5; i++){
                int count = 1;
                for(int j = i+1; j < i+4; j++){
                    if(playerCard.getCard()[i].getValue() - i == playerCard.getCard()[j].getValue() - j){
                        count ++;
                    }
                    if(count == 5){
                        str = true;
                        index = i;
                        break;
                    }
                }
            }
            if(str){
                for(int i = index ; i<index+5; i++){
                    SFCard.push_back(playerCard.getCard()[i]);
                }
            }
            return SFCard;
        }
        vector<Card> value(){
            bubbleSort();
            if(straightFlush().size() == 5){
                return straightFlush();
            }
            else if(FourOfKind().size() == 4){
                return FourOfKind();
            }
            else if(FullHouse().size() == 5){
                return FullHouse();
            }
            else if(Flush().size() == 5 ){
                return Flush();
            }
            else if(straight().size() == 5){
                return straight();
            }
            else if(threeOfKind().size() == 3){
                return threeOfKind();
            }
            else if(PairCard().size() == 4){
                return PairCard();
            }
            else if(PairCard().size() == 2){
                return PairCard();
            }
            else{
                vector<Card> high;
                high.push_back(getHighCard());
                return high;
            }
        }
};

#endif