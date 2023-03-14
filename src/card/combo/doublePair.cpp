#include "doublePair.hpp"
#include "../../enum/colors.hpp"

doublePairCombo::doublePairCombo(vector<Card> cards){
    this->cards=cards;
}

double doublePairCombo::getValue() const {
    int number=0;
    int color_number=0;
    for(int i=0;i<cards.size();i++){
        if(number<cards[i].getNumber()){
            number=cards[i].getNumber();
        }
        }
        for(int i=0;i<cards.size();i++){
            if(number==cards[i].getNumber()){
                int temp_color=colors[cards[i].getColor()] + 1;
                if(color_number<temp_color){
                    color_number=temp_color;
                }
            }
        }
        return 2.7+(number-1)*0.1+color_number*0.03;
    };
