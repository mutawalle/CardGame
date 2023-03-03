#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class threeKind :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        threeKind(vector<Card> cards){
            this->cards=cards;
        }
        double getValue(){
            int number=cards[0].getNumber();
            int number_color=0;
            for(int i=0;i<cards.size();i++){
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
            
            return 4+(number-1)*0.1+number_color*0.03;
        };
};