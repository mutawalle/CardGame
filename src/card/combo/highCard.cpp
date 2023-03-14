#include "highCard.hpp"
#include "../../enum/colors.hpp"

highCard::highCard(Card cards){
    this->cards=cards;
}

double highCard::getValue() const {
    return cards.getValue();
};