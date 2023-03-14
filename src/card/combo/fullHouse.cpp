#include "fullHouse.hpp"
#include "../../enum/colors.hpp"

fullHouseCombo::fullHouseCombo(vector<Card> cards){
    this->cards=cards;
}

double fullHouseCombo::getValue() const {
    int highest_number=0;
    int n01,n02,cnt1,cnt2;
    n01=cards[0].getNumber();
    n02=0;
    cnt1=1;
    cnt2=0;
    for(int i=0;i<cards.size();i++){
        if(cards[i].getNumber()==n01){
            cnt1++;
        }
        else{
            n02=cards[i].getNumber();
            cnt2++;
        }
    }
    if(cnt1>cnt2){
        highest_number=n01;
    }
    else{
        highest_number=n02;
    }
    int color_number=0;
    for(int i=0;i<cards.size();i++){
        if(highest_number==cards[i].getNumber()){
            int temp_color=colors[cards[i].getColor()];
            if(color_number<temp_color){
                color_number=temp_color;
            }
        }
    }
    
    return 7.9+(highest_number-1)*0.1+color_number*0.03;
};

// 3H 3B 3M 4H 4B