#include "threeKind.hpp"
#include <map>
#include <string>

using namespace std;

map<string, int> colorsThreeKind = {{"HIJAU", 0}, {"BIRU", 1}, {"KUNING", 2}, {"MERAH", 3}};

threeKindCombo::threeKindCombo(vector<Card> cards){
    this->cards=cards;
}

double threeKindCombo::getValue() const {
    int number=cards[0].getNumber();
    int number_color=0;
    for(size_t i=0;i<cards.size();i++){
        int temp_color=colorsThreeKind[cards[i].getColor()] + 1;
        if(number_color<temp_color){
            number_color=temp_color;
        }
    }
    
    return 4+(number-1)*0.1+(number_color-1)*0.03;
};