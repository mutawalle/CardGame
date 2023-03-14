#include "../abstractValue.hpp"
#include "../card.hpp"

#include <vector>

class twoPair :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        twoPair(vector<Card> cards){
            this->cards=cards;
        }
        double getValue() const override{
            int number=0;
            int color_number=0;
            for(int i=0;i<cards.size();i++){
                if(number<cards[i].getNumber()){
                    number=cards[i].getNumber();
                }
            }
            for(int i=0;i<cards.size();i++){
                if(number==cards[i].getNumber()){
                    int temp_color=colors[cards[i].getColor()] + 1;
                    if(color_number<temp_color){
                        color_number=temp_color;
                    }
                }
            }
            return 2.7+(number-1)*0.1+(color_number-1)*0.03;
        };
};