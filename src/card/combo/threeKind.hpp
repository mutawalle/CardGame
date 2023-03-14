#include "../abstractValue.hpp"
#include "../card.hpp"
#include "../../enum/colors.hpp"

#include <vector>

class threeKindCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        threeKindCombo(vector<Card> cards){
            this->cards=cards;
        }
        double getValue() const override{
            int number=cards[0].getNumber();
            int number_color=0;
            for(int i=0;i<cards.size();i++){
                int temp_color=colors[cards[i].getColor()] + 1;
                if(number_color<temp_color){
                    number_color=temp_color;
                }
            }
            
            return 4+(number-1)*0.1+(number_color-1)*0.03;
        };
};