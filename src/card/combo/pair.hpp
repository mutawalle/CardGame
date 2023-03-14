#ifndef PAIR_HPP
#define PAIR_HPP

#include "../abstractValue.hpp"
#include "../card.hpp"

#include <vector>

class PairCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        PairCombo(vector<Card> cards);

        double getValue() const override;
};

#endif