#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP

#include "../abstractValue.hpp"
#include "../card.hpp"

#include <vector>

class straightFlushCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        straightFlushCombo(vector<Card> cards);
        double getValue() const override;
};

#endif