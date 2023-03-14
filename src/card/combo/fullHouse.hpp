#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include "../abstractValue.hpp"
#include "../card.hpp"

#include <vector>

class fullHouseCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        fullHouseCombo(vector<Card> cards);
        double getValue() const override;
};

#endif