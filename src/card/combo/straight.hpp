#include "../abstractValue.hpp"
#include "../card.hpp"
#include "../../enum/colors.hpp"

#include <vector>
//salah
class straightCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        straightCombo(vector<Card> cards){
            this->cards=cards;
        }
        double getValue() const override{
            int color_number=0;
            int number=0;
            int idx=0;
            
            for(int i=0;i<cards.size();i++){
                if(number<cards[i].getNumber()){
                    number=cards[i].getNumber();
                    idx=i;
                }
            }

            color_number = colors[cards[idx].getColor()] + 1;
            return 5.3+(number-1)*0.1+(color_number-1)*0.03;
        };
};