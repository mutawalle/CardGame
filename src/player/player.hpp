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

        void sorting() {
            sort(playerCard.getCard().begin(),playerCard.getCard().end());
            // for (int i = 0; i < playerCard.getCard().size(); i++) {
            //     for (int j = i+1; j < playerCard.getCard().size(); j++) {
            //         if (playerCard.getCard()[i].getNumber() > playerCard.getCard()[j].getNumber()) {
            //             Card temp = playerCard.getCard()[j];
            //             playerCard.getCard()[j] = playerCard.getCard()[i];
            //             playerCard.getCard()[i] = temp;
            //         }
            //     }
            // }
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
            vector<Card> straightVec;
            int idx=0,value=0;
            for(int i=1;i<playerCard.getCard().size();i++){
                if(playerCard.getCard()[i].getNumber()-playerCard.getCard()[i-1].getNumber()==0 || playerCard.getCard()[i].getNumber()-playerCard.getCard()[i-1].getNumber()==1){
                    value++;
                    // straightvec push
                }
                else{
                    value=0;
                    // straightVec delete
                }

                if(value>=4){
                    idx=i;
                }
            }
            int jarak=playerCard.getCard()[idx].getNumber();
            int currentNumber=jarak;
            straightVec.push_back(playerCard.getCard()[idx]);
            for(int i=jarak-1;i>=0;i--){
                // straightVec.push_back(playerCard.getCard()[i]);
                if(currentNumber-playerCard.getCard()[i].getNumber()==1){
                    currentNumber--;
                    straightVec.push_back(playerCard.getCard()[i]);
                }
            }
            // //vector sudah terurut
            // int index = 0;
            // vector<Card> straightVec;
            // bool str = false;
            // for(int i = 0; i <= playerCard.getCard().size()-5; i++){
            //     int count = 1;
            //     for(int j = i+1; j < i+4; j++){
            //         if(playerCard.getCard()[i].getNumber() - i == playerCard.getCard()[j].getNumber() - j){
            //             count ++;
            //         }
            //         if(count == 5){
            //             str = true;
            //             index = i;
            //             break;
            //         }
            //     }
            // }
            // if(str){
            //     for(int i = index ; i<index+5; i++){
            //         straightVec.push_back(playerCard.getCard()[i]);
            //     }
            // }
            
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
                    if(count == 4){
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
            int index;
            int number1 = 0;
            for(int i = playerCard.getCardListLength()-1; i>=2; i--){
                if(playerCard.getCard()[i].getNumber() == playerCard.getCard()[i-1].getNumber() && playerCard.getCard()[i].getNumber() == playerCard.getCard()[i-2].getNumber()){
                    number1 = playerCard.getCard()[i].getNumber();
                    index = i-2;
                    break;
                }
            }
            if(number1 == 0){
                return temp;
            }
            else{
                for(int i = index; i < index+3; i++){
                    temp.push_back(playerCard.getCard()[i]);
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
            return temp;
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
            vector<int> temp;
            bool str = false;
            // int index = 0;
            for(int i = 0; i <= playerCard.getCard().size()-5; i++){
                int count = 1;
                vector<int> index;
                index.push_back(i);
                for(int j = i+1; j < playerCard.getCard().size(); j++){
                    if(playerCard.getCard()[j].getValue()*10 - playerCard.getCard()[index[count-1]].getValue()*10 == 1){
                        count ++;
                        index.push_back(j);
                    }
                    if(count == 5){
                        // cout<<"count : ";
                        // cout<<count<<endl;
                        str = true;
                        temp = index;
                        // index = i;
                        break;
                    }
                }
            }
            
            if(str){
                for(int i = 0; i<temp.size(); i++){
                    SFCard.push_back(playerCard.getCard()[temp[i]]);
                }
                // for(int i = index ; i<index+5; i++){
                //     SFCard.push_back(playerCard.getCard()[i]);
                // }
            }
            if(SFCard.size() == 5){
                return SFCard;
            }
            else{
                return {};
            }
            // vector<Card> SFCard;
            // bool str = false;
            // int index = 0;
            // for(int i = 0; i <= playerCard.getCard().size()-5; i++){
            //     int count = 1;
            //     for(int j = i+1; j <= i+4; j++){
            //         if(playerCard.getCard()[i].getValue()*10 - i == playerCard.getCard()[j].getValue()*10 - j){
            //             count ++;
            //         }
            //         if(count == 5){
            //             cout<<"count : ";
            //             cout<<count<<endl;
            //             str = true;
            //             index = i;
            //             break;
            //         }
            //     }
            // }
            
            // if(str){
            //     for(int i = index ; i<index+5; i++){
            //         SFCard.push_back(playerCard.getCard()[i]);
            //     }
            // }
            // return SFCard;
        }
        vector<Card> value(){
            sorting();
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