#ifndef THREEKIND_HPP
#define THREEKIND_HPP

#include "../abstractValue.hpp"
#include "../card.hpp"

#include <vector>

class threeKindCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        threeKindCombo(vector<Card> cards);
        double getValue() const override;
};

#endif