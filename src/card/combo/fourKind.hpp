#ifndef FOURKIND_HPP
#define FOURKIND_HPP

#include "../abstractValue.hpp"
#include "../card.hpp"

#include <vector>

class fourKindCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        fourKindCombo(vector<Card> cards);
        double getValue() const override ;
};

#endif