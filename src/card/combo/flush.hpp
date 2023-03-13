#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class flushCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        flushCombo(vector<Card> cards){
            this->cards=cards;
        }
        double getValue() const override{
            int color_number=0;
            int number=0;
            if(cards[0].getColor()=="Hijau"){
                color_number=1;
            }
            if(cards[0].getColor()=="Biru"){
                color_number=2;
            }
            if(cards[0].getColor()=="Kuning"){
                color_number=3;
            }
            if(cards[0].getColor()=="Merah"){
                color_number=4;
            }
            for(int i=0;i<cards.size();i++){
                if(number<cards[i].getNumber()){
                    number=cards[i].getNumber();
                }
            }
            
            return 6.6+(number-1)*0.1+(color_number-1)*0.03;
        };
};