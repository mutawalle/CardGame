#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>
//salah
class straightCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        straightCombo(vector<Card> cards){
            this->cards=cards;
        }
        double getValue() const override{
            int color_number=0;
            int number=0;
            int idx=0;
            
            for(int i=0;i<cards.size();i++){
                if(number<cards[i].getNumber()){
                    number=cards[i].getNumber();
                    idx=i;
                }
            }
            if(cards[idx].getColor()=="Hijau"){
                color_number=1;
            }
            if(cards[idx].getColor()=="Biru"){
                color_number=2;
            }
            if(cards[idx].getColor()=="Kuning"){
                color_number=3;
            }
            if(cards[idx].getColor()=="Merah"){
                color_number=4;
            }
            return 5.3+(number-1)*0.1+(color_number-1)*0.03;
        };
};