// parent dari card
#ifndef CARD_HPP
#define CARD_HPP

#include "abstractValue.hpp"

#include <map>
#include <string>
#include <iostream>

using namespace std;

class Card : public AbstractValue {

    private:
        int number;
        string color;
        double value;

    public:
        Card();
        Card(int, string, double);
        Card(int, string);
        Card(const Card&);
        ~Card();
        Card& operator=(const Card& other);
        double getValue() const override;
        int getNumber() const;
        string getColor() const;
        friend ostream& operator<<(ostream& os, const Card& obj);
        bool operator==(const Card& other);
};

#endif