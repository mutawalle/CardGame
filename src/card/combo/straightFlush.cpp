#include "straightFlush.hpp"
#include <map>
#include <string>

using namespace std;

map<string, int> colorsStraightFlush = {{"HIJAU", 0}, {"BIRU", 1}, {"KUNING", 2}, {"MERAH", 3}};

straightFlushCombo::straightFlushCombo(vector<Card> cards){
    this->cards=cards;
}

double straightFlushCombo::getValue() const {
    int color_number=colorsStraightFlush[cards[0].getColor()];
    int number=0;
    for(int i=0;i<cards.size();i++){
        if(number<cards[i].getNumber()){
            number=cards[i].getNumber();
        }
    }
    
    return 10.5+(number-1)*0.1+(color_number)*0.03;
};

// 3H 4H 5H 6H 7H