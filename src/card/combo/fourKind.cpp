#include "fourKind.hpp"

fourKindCombo::fourKindCombo(vector<Card> cards){
    this->cards=cards;
}

double fourKindCombo::getValue() const {
    int highest_number=cards[0].getNumber();
    
    return 9.2+(highest_number-1)*0.1;
};

// 4H 4B 4M 4K