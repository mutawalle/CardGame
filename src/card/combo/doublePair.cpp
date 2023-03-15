#include "doublePair.hpp"
#include <map>
#include <string>

using namespace std;

map<string, int> colorsDoublePair = {{"HIJAU", 0}, {"BIRU", 1}, {"KUNING", 2}, {"MERAH", 3}};

doublePairCombo::doublePairCombo(vector<Card> cards){
    this->cards.first.first=cards[0];
    this->cards.first.second=cards[1];
    this->cards.second.first=cards[2];
    this->cards.second.second=cards[3];
}

double doublePairCombo::getValue() const {
    int number=0;
    int color_number=0;

    if(number<=this->cards.first.first.getNumber()){
        number=this->cards.first.first.getNumber();
    }
    if(number<=this->cards.second.first.getNumber()){
        number=this->cards.second.first.getNumber();
    }
    if(number<=this->cards.first.second.getNumber()){
        number=this->cards.first.second.getNumber();
    }
    if(number<=this->cards.second.second.getNumber()){
        number=this->cards.second.second.getNumber();
    }
    
    if(number==this->cards.first.first.getNumber()){
        if(color_number<colorsDoublePair[this->cards.first.first.getColor()]){
            color_number=colorsDoublePair[this->cards.first.first.getColor()];
        }
    }
    if(number==this->cards.second.first.getNumber()){
        if(color_number<colorsDoublePair[this->cards.second.first.getColor()]){
            color_number=colorsDoublePair[this->cards.second.first.getColor()];
        }
    }
    if(number==this->cards.first.second.getNumber()){
        if(color_number<colorsDoublePair[this->cards.first.second.getColor()]){
            color_number=colorsDoublePair[this->cards.first.second.getColor()];
        }
    }
    if(number==this->cards.second.second.getNumber()){
        if(color_number<colorsDoublePair[this->cards.second.second.getColor()]){
            color_number=colorsDoublePair[this->cards.second.second.getColor()];
        }
    }

    return 2.7+(number-1)*0.1+color_number*0.03;
};

// 2H 2B 3H 3B