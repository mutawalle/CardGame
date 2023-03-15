#include "pair.hpp"
#include <map>
#include <string>

using namespace std;

map<string, int> colorsPair = {{"HIJAU", 0}, {"BIRU", 1}, {"KUNING", 2}, {"MERAH", 3}};

PairCombo::PairCombo(vector<Card> cards){
    this->cards.first=cards[0];
    this->cards.second=cards[1];
}

double PairCombo::getValue() const {
    int number=cards.first.getNumber();
    int color_number=0;
    if(colorsPair[cards.first.getColor()] > colorsPair[cards.second.getColor()]){
        color_number=colorsPair[cards.first.getColor()];
    }else{
        color_number=colorsPair[cards.second.getColor()];
    }
    return 1.4+(number-1)*0.1+color_number*0.03;

};

// 2H 2B