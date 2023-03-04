#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class doublePair :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        doublePair(vector<Card> cards){
            this->cards=cards;
        }
        double getValue() const override{
            int number=0;
            int number_color=0;
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
                    if(number_color<temp_color){
                        number_color=temp_color;
                    }
                }
            }
            return 2.7+number*0.1+number_color*0.03;
        };
};