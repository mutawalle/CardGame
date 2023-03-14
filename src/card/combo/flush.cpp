#include "flush.hpp"
#include "../../enum/colors.hpp"

flushCombo::flushCombo(vector<Card> cards){
    this->cards=cards;
}

double flushCombo::getValue() const {
    int color_number=colors[cards[0].getColor()];
    int number=0;
    for(int i=0;i<cards.size();i++){
        if(number<cards[i].getNumber()){
            number=cards[i].getNumber();
        }
    }
    
    return 6.6+(number-1)*0.1+color_number*0.03;
};

// 3H 4H 10H 12H 13H