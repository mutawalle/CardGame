#ifndef HIGHCARD_HPP
#define HIGHCARD_HPP

#include "../abstractValue.hpp"
#include "../card.hpp"
#include <vector>

class highCard :public AbstractValue {
    private:
        Card cards;
    public:
        highCard(Card cards);
        double getValue() const override;
};

#endif