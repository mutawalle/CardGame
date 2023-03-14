#ifndef DOUBLEPAIR_HPP
#define DOUBLEPAIR_HPP


#include "../abstractValue.hpp"
#include "../card.hpp"

#include <vector>

class doublePairCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        doublePairCombo(vector<Card> cards);
        double getValue() const override;
};

#endif