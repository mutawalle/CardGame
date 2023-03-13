#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class fullHouseCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        fullHouseCombo(vector<Card> cards){
            this->cards=cards;
        }
        double getValue() const override{
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
                    int temp_color=0;
                    if(cards[i].getColor()=="Hijau"){
                        temp_color=1;
                    }
                    if(cards[i].getColor()=="Biru"){
                        temp_color=2;
                    }
                    if(cards[i].getColor()=="Kuning"){
                        temp_color=3;
                    }
                    if(cards[i].getColor()=="Merah"){
                        temp_color=4;
                    }
                    if(color_number<temp_color){
                        color_number=temp_color;
                    }
                }
            }
            
            return 7.9+(highest_number-1)*0.1+(color_number-1)*0.03;
        };
};