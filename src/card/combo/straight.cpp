#include "straight.hpp"
#include "../../enum/colors.hpp"

straightCombo::straightCombo(vector<Card> cards){
    this->cards=cards;
}

double straightCombo::getValue() const {
    int color_number=0;
    int number=0;
    int idx=0;
    
    for(int i=0;i<cards.size();i++){
        if(number<cards[i].getNumber()){
            number=cards[i].getNumber();
            idx=i;
        }
    }

    color_number = colors[cards[idx].getColor()];
    return 5.3+(number-1)*0.1+color_number*0.03;
};
// 3H 4B 5H 6B 7H