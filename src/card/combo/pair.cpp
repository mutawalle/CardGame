#include "pair.hpp"
#include "../../enum/colors.hpp"

PairCombo::PairCombo(vector<Card> cards){
    this->cards=cards;
}

double PairCombo::getValue() const {
    int number=cards[0].getNumber();
    int color_number=0;
    double res;
    if(colors[cards[0].getColor()] > colors[cards[1].getColor()]){
        color_number=colors[cards[0].getColor()];
    }else{
        color_number=colors[cards[1].getColor()];
    }
    return 1.4+(number-1)*0.1+color_number*0.03;

};

// 2H 2B