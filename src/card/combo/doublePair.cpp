#include "doublePair.hpp"
#include <map>
#include <string>

using namespace std;

map<string, int> colorsDoublePair = {{"HIJAU", 0}, {"BIRU", 1}, {"KUNING", 2}, {"MERAH", 3}};

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
            int temp_color=colorsDoublePair[cards[i].getColor()];
            if(color_number<temp_color){
                color_number=temp_color;
            }
        }
    }
    return 2.7+(number-1)*0.1+color_number*0.03;
};

