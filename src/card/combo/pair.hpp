#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class Pair :public AbstractValue {
    private:
        pair<Card,Card> cards;
    public:
        Pair(pair<Card,Card> cards){
            this->cards=cards;
        }
        double getValue(){
            int number=cards.first.getNumber();
            int color_number=0;
            double res;
            if(cards.first.getColor()=="Hijau" || cards.second.getColor()=="Hijau"){
                color_number=1;
            }
            if(cards.first.getColor()=="Biru" || cards.second.getColor()=="Biru"){
                color_number=2;
            }
            if(cards.first.getColor()=="Kuning" || cards.second.getColor()=="Kuning"){
                color_number=3;
            }
            if(cards.first.getColor()=="Merah" || cards.second.getColor()=="Merah"){
                color_number=4;
            }
            return 1.4+(number-1)*0.1+color_number*0.03;

        };
};