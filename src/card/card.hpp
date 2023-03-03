// parent dari card
#ifndef CARD_HPP
#define CARD_HPP

#include "abstractValue.hpp"
#include <string>

using namespace std;

class Card : AbstractValue {

    private:
        int number;
        string color;
        double value;

    public:
        Card();
        Card(int, string, double);
        Card(const Card&);
        ~Card();
        Card& operator=(const Card& other);
        double getValue() const override;
        int getNumber() const;
};

#endif