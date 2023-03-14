#include "pair.hpp"
#include <map>
#include <string>

using namespace std;

map<string, int> colorsPair = {{"HIJAU", 0}, {"BIRU", 1}, {"KUNING", 2}, {"MERAH", 3}};

PairCombo::PairCombo(vector<Card> cards){
    this->cards=cards;
}

double PairCombo::getValue() const {
    int number=cards[0].getNumber();
    int color_number=0;
    if(colorsPair[cards[0].getColor()] > colorsPair[cards[1].getColor()]){
        color_number=colorsPair[cards[0].getColor()];
    }else{
        color_number=colorsPair[cards[1].getColor()];
    }
    return 1.4+(number-1)*0.1+color_number*0.03;

};

// 2H 2B