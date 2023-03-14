#ifndef FLUSH_HPP
#define FLUSH_HPP

#include "../abstractValue.hpp"
#include "../card.hpp"

#include <vector>

class flushCombo :public AbstractValue {
    private:
        vector<Card> cards;
    public:
        flushCombo(vector<Card> cards);
        
        double getValue() const override;
};

#endif