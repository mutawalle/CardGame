#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class fourKind :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        fourKind(vector<Card> cards){
            this->cards=cards;
        }
        double getValue() const override {
            int highest_number=cards[0].getNumber();
            
            return 9.2+(highest_number-1)*0.1;
        };
};