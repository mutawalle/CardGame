#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class twoPair :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        twoPair(vector<Card> cards){
            this->cards=cards;
        }
        double getValue() const override{
            int number=0;
            int color_number=0;
            for(int i=0;i<cards.size();i++){
                if(number<cards[i].getNumber()){
                    number=cards[i].getNumber();
                }
            }
            for(int i=0;i<cards.size();i++){
                if(number==cards[i].getNumber()){
                    int temp_color=0;
                    if(cards[i].getColor()=="Hijau"){
                        temp_color=1;
                    }
                    if(cards[i].getColor()=="Biru"){
                        temp_color=2;
                    }
                    if(cards[i].getColor()=="Kuning"){
                        temp_color=3;
                    }
                    if(cards[i].getColor()=="Merah"){
                        temp_color=4;
                    }
                    if(color_number<temp_color){
                        color_number=temp_color;
                    }
                }
            }
            return 2.7+(number-1)*0.1+(color_number-1)*0.03;
        };
};