#include "../abstractValue.hpp"
#include "../card.hpp"

#include <vector>

class PairCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        PairCombo(vector<Card> cards){
            this->cards=cards;
        }

        double getValue() const override{
            int number=cards[0].getNumber();
            int color_number=0;
            double res;
            if(colors[cards[0].getColor()] > colors[cards[1].getColor()]){
                color_number=colors[cards[0].getColor()] + 1;
            }else{
                color_number=colors[cards[1].getColor()] + 1;
            }
            return 1.4+(number-1)*0.1+(color_number-1)*0.03;

        };
};