#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class highCard :public AbstractValue {
    private:
        Card cards;
    public:
        highCard(Card cards){
            this->cards=cards;
        }
        double getValue(){
            return cards.getValue();

        };
};