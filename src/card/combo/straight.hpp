#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP

#include "../abstractValue.hpp"
#include "../card.hpp"

#include <vector>
//salah
class straightCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        straightCombo(vector<Card> cards);
        double getValue() const override;
};

#endif