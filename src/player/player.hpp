#ifndef PLAYER_H
#define PLAYER_H

#include "../card/playerCard.hpp"
#include "../card/card.hpp"

//combo
#include "../card/combo/doublePair.hpp"
#include "../card/combo/flush.hpp"
#include "../card/combo/fourKind.hpp"
#include "../card/combo/fullHouse.hpp"
#include "../card/combo/highCard.hpp"
#include "../card/combo/pair.hpp"
#include "../card/combo/straight.hpp"
#include "../card/combo/straightFlush.hpp"
#include "../card/combo/threeKind.hpp"

#include <bits/stdc++.h>

using namespace std;

class Player {
    private:
        string name;
        PlayerCard playerCard;
        string ability;
        long long int point;
        bool isAbilityLess;
        double value;
    public:
        Player(): playerCard(){
            name = "";
            ability = "";
            point = 0;
            isAbilityLess = false;
            value = 0;
        }
        Player(string _name, PlayerCard pc, string _abillity, long long int _poin, double _value): playerCard(pc){
            name = _name;
            ability = _abillity;
            point = _poin;
            isAbilityLess = false;
            value = _value;
        }
        Player(const Player& other): playerCard(other.playerCard){
            name = other.name;
            ability = other.ability;
            point = other.point;
            isAbilityLess = other.isAbilityLess;
            value = other.value;
        }

        PlayerCard getPlayerCard (){
            return playerCard;
        }

        vector<Card> sorting() {
            vector<Card> playerCards = playerCard.getCard();
            sort(playerCards.begin(), playerCards.end());
            return playerCards;
        }
        string getAbility(){
            return ability;
        }

        long long int getPoint(){
            return point;
        }

        void setPoint(long long int point){
            this->point = point;
        }

        double getValue(){
            return this->value;
        }

        string getName (){
            return this-> name;
        }
        void setName(string name){
            this->name = name;
        }
        void setAbilityLess (bool isAbilityLess){
            this->isAbilityLess = isAbilityLess;
        }

        bool getIsAbilityLess (){
            return isAbilityLess;
        }
        void setAbility(string ability){
            this->ability = ability;
        }

        void setPlayerCard(PlayerCard playerCard){
            this->playerCard = playerCard;
        }

        Card getHighCard (vector<Card> listCard){
            Card card = listCard[0];
            for(size_t i = 1; i < listCard.size(); i++){
                if(card.getValue() < listCard[i].getValue()){
                    card = listCard[i];
                }
            }
            return card;
        }
        vector<Card> PairCard (vector<Card> listCard){
            int pairCount = 0;
            vector<Card> pair;
            for(size_t i = 0; i <=listCard.size() -1 ; i++){
                for(size_t j = i+1; j <=listCard.size(); j++){
                    if(listCard[i].getNumber() == listCard[j].getNumber()){
                        pairCount += 1;
                        pair.push_back(listCard[i]);
                        pair.push_back(listCard[j]);
                        break;
                    }
                }
            }
            return pair;
        }

        vector<Card> threeOfKind(vector<Card> listCard){
            vector<Card> Three;
            for(int i = listCard.size()-1; i>=2; i--){
                if(listCard[i].getNumber() == listCard[i-1].getNumber() && listCard[i].getNumber() == listCard[i-2].getNumber()){
                    Three.push_back(listCard[i]);
                    Three.push_back(listCard[i-1]);
                    Three.push_back(listCard[i-2]);
                    break;
                }
            }
            return Three;
        }

        vector<Card> straight (vector<Card> listCard){
            vector<Card> straightVec;
            int idx=0,value=0;
            for(size_t i=1;i<=listCard.size();i++){
                if(listCard[i].getNumber()-listCard[i-1].getNumber()==0 || listCard[i].getNumber()-listCard[i-1].getNumber()==1){
                    value++;
                }
                else{
                    value=0;
                }

                if(value>=4){
                    idx=i;
                }
            }
            int jarak=listCard[idx].getNumber();
            int currentNumber=jarak;
            straightVec.push_back(listCard[idx]);
            for(int i=jarak-1;i>=0;i--){
                if(currentNumber-listCard[i].getNumber()==1){
                    currentNumber--;
                    straightVec.push_back(listCard[i]);
                }
            }
            
            return straightVec;
        }

        vector<Card> Flush (vector<Card> listCard){
            //Total kartu ada 7, jadi maksimal hanya ada 1 kombinasi flush
            bool isFlush = false;
            vector<Card> FlushCard;
            string color;
            for(size_t i = 0; i<playerCard.getCardListLength(); i++){
                int count = 0;
                for(size_t j = i+1; j < playerCard.getCardListLength(); j++){
                    if(listCard[i].getColor() == listCard[j].getColor()){
                        count ++;
                    }
                    if(count == 4){
                        isFlush = true;
                        color = listCard[i].getColor();
                    }
                }
            }
            if(isFlush){
                int i = playerCard.getCardListLength() - 1;
                while(FlushCard.size() < 5){
                    if(listCard[i].getColor() == color){
                        FlushCard.push_back(listCard[i]);
                    }
                    i--;
                }
            }
            return FlushCard;
        }
        
        vector<Card> FullHouse (vector<Card> listCard){
            vector<Card> temp;
            int index;
            int number1 = 0;
            for(int i = playerCard.getCardListLength()-1; i>=2; i--){
                if(listCard[i].getNumber() == listCard[i-1].getNumber() && listCard[i].getNumber() == listCard[i-2].getNumber()){
                    number1 = listCard[i].getNumber();
                    index = i-2;
                    break;
                }
            }
            if(number1 == 0){
                return temp;
            }
            else{
                for(int i = index; i < index+3; i++){
                    temp.push_back(listCard[i]);
                }
                for(int i = playerCard.getCardListLength()-1; i>=1; i--){
                    if(listCard[i].getNumber() == listCard[i-1].getNumber() && listCard[i].getNumber() != number1){
                        temp.push_back(listCard[i]);
                        temp.push_back(listCard[i-1]);
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

        vector<Card> FourOfKind (vector<Card> listCard){
            vector<Card> FOKcard;
            for(int i = playerCard.getCardListLength()-1; i>= 3; i--){
                bool found = true;
                for(int j = 1; j < 4; j++){
                    if(listCard[i].getNumber() != listCard[i-j].getNumber()){
                        found = false;
                    }
                }
                if(found){
                    for(int k = i; k>=i-3; k--){
                        FOKcard.push_back(listCard[k]);
                    }
                    break;
                }
            }
            return FOKcard;
        }

        vector<Card> straightFlush(vector<Card> listCard){
            vector<Card> SFCard;
            vector<int> temp;
            bool str = false;
            for(int i = 0; i <= listCard.size()-5; i++){
                int count = 1;
                vector<int> index;
                index.push_back(i);
                for(int j = i+1; j < listCard.size(); j++){
                    if((listCard[j].getNumber() - listCard[index[count-1]].getNumber() == 1) && (listCard[j].getColor()== listCard[index[count-1]].getColor())){
                        count ++;
                        index.push_back(j);
                    }
                    if(count == 5){
                        str = true;
                        temp = index;
                        break;
                    }
                }
            }
            
            if(str){
                for(size_t i = 0; i<temp.size(); i++){
                    SFCard.push_back(listCard[temp[i]]);
                }
            }
            if(SFCard.size() == 5){
                return SFCard;
            }
            else{
                return {};
            }
        }
        void setValue(){
            vector<Card> listCard = sorting();
            if(straightFlush(listCard).size() == 5){
                // for(int i=0;i<5;i++){
                //     cout<<"asu"<<endl;
                //     cout<<straightFlush(listCard)[i]<<endl;
                // }
                this->value = straightFlushCombo(straightFlush(listCard)).getValue();
                return;
            }
            else if(FourOfKind(listCard).size() == 4){
                // cout << "fourkind" << endl;
                this->value = fourKindCombo(FourOfKind(listCard)).getValue();
                // for(int i=0;i<4;i++){
                //     cout<<FourOfKind(listCard)[i]<<endl;
                // }
            }
            else if(FullHouse(listCard).size() == 5){
                // cout << "fullhouse" << endl;
                this->value = fullHouseCombo(FullHouse(listCard)).getValue();
                // for(int i=0;i<5;i++){
                //     cout<<FullHouse(listCard)[i]<<endl;
                // }
            }
            else if(Flush(listCard).size() == 5 ){
                // cout << "fLush" << endl;
                this->value = flushCombo(Flush(listCard)).getValue();
                // for(int i=0;i<5;i++){
                //     cout<<Flush(listCard)[i]<<endl;
                // }
            }
            else if(straight(listCard).size() == 5){
                // cout << "straight" << endl;
                this->value = straightCombo(straight(listCard)).getValue();
                // for(int i=0;i<5;i++){
                //     cout<<straight(listCard)[i]<<endl;
                // }
            }
            else if(threeOfKind(listCard).size() == 3){
                // cout << "three kind" << endl;
                this->value = threeKindCombo(threeOfKind(listCard)).getValue();
                // for(int i=0;i<3;i++){
                //     cout<<threeOfKind(listCard)[i]<<endl;
                // }
            }
            else if(PairCard(listCard).size() == 4){
                // cout << "double oari" << endl;
                this->value = doublePairCombo(PairCard(listCard)).getValue();
                // for(int i=0;i<4;i++){
                //     cout<<PairCard(listCard)[i]<<endl;
                // }
            }
            else if(PairCard(listCard).size() == 2){
                // cout << "pair" << endl;
                this->value = PairCombo(PairCard(listCard)).getValue();
                // for(int i=0;i<2;i++){
                //     cout<<PairCard(listCard)[i]<<endl;
                // }
            }
            else{
                vector<Card> high;
                high.push_back(getHighCard(listCard));
                this->value = high[0].getValue();
            }
        }

        bool operator>(Player& other) {
            if(this->value == other.value){
                double player1, player2;
                vector<Card> player1Cards = this->getPlayerCard().getCard();
                vector<Card> player2Cards = other.getPlayerCard().getCard();

                player1Cards.erase(player1Cards.begin()+2, player1Cards.end());
                player2Cards.erase(player2Cards.begin()+2, player2Cards.end());

                //Player 1
                if(player1Cards.at(0).getNumber() == player1Cards.at(1).getNumber()){
                    player1 = PairCombo(player1Cards).getValue();
                }else{
                    if(player1Cards.at(0).getValue() > player1Cards.at(1).getValue()){
                        player1 = player1Cards.at(0).getValue();
                    }else{
                        player1 = player1Cards.at(1).getValue();
                    }
                }

                // Player 2
                if(player2Cards.at(0).getNumber() == player2Cards.at(1).getNumber()){
                    player2 = PairCombo(player2Cards).getValue();
                }else{
                    if(player2Cards.at(0).getValue() > player2Cards.at(1).getValue()){
                        player2 = player2Cards.at(0).getValue();
                    }else{
                        player2 = player2Cards.at(1).getValue();
                    }
                }
                return player1 > player2;
            }else{
                return this->value > other.value;
            }
        }

        bool operator<(Player& other) {
            if(this->value == other.value){
                double player1, player2;
                vector<Card> player1Cards = this->getPlayerCard().getCard();
                vector<Card> player2Cards = other.getPlayerCard().getCard();

                player1Cards.erase(player1Cards.begin()+2, player1Cards.end());
                player2Cards.erase(player2Cards.begin()+2, player2Cards.end());

                //Player 1
                if(player1Cards.at(0).getNumber() == player1Cards.at(1).getNumber()){
                    player1 = PairCombo(player1Cards).getValue();
                }else{
                    if(player1Cards.at(0).getValue() > player1Cards.at(1).getValue()){
                        player1 = player1Cards.at(0).getValue();
                    }else{
                        player1 = player1Cards.at(1).getValue();
                    }
                }

                // Player 2
                if(player2Cards.at(0).getNumber() == player2Cards.at(1).getNumber()){
                    player2 = PairCombo(player2Cards).getValue();
                }else{
                    if(player2Cards.at(0).getValue() > player2Cards.at(1).getValue()){
                        player2 = player2Cards.at(0).getValue();
                    }else{
                        player2 = player2Cards.at(1).getValue();
                    }
                }
                cout << this->getName() << ": " << player1 << " vs " << other.getName() << ": " << player2 << endl;
                return player1 < player2;
            }else{
                return this->value < other.value;
            }
        }

        bool operator==(const Player& other) {
            return this->value == other.value;
        }
};

#endif