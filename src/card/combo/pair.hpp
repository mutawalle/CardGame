#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class PairCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        PairCombo(vector<Card> cards){
            this->cards=cards;
        }

        double getValue() const override{
            int number=cards[0].getNumber();
            int color_number=0;
            double res;
            if(cards[0].getColor()=="Hijau" || cards[1].getColor()=="Hijau"){
                color_number=1;
            }
            if(cards[0].getColor()=="Biru" || cards[1].getColor()=="Biru"){
                color_number=2;
            }
            if(cards[0].getColor()=="Kuning" || cards[1].getColor()=="Kuning"){
                color_number=3;
            }
            if(cards[0].getColor()=="Merah" || cards[1].getColor()=="Merah"){
                color_number=4;
            }
            return 1.4+(number-1)*0.1+(color_number-1)*0.03;

        };
};