#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class fullHouse :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        fullHouse(vector<Card> cards){
            this->cards=cards;
        }
        double getValue(){
            int highest_number=0;
            for(int i=0;i<cards.size();i++){
                if(highest_number<cards[i].getNumber()){
                    highest_number=cards[i].getNumber();
                }
            }
            int color_number=0;
            for(int i=0;i<cards.size();i++){
                if(highest_number==cards[i].getNumber()){
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
            
            return 7.9+(highest_number-1)*0.1+color_number*0.03;
        };
};