// class abstrak untuk diturunkan menjadi PlayerCard dan DeckCard
#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include "card.hpp"

class InventoryHolder {
    public:
        virtual InventoryHolder& operator+(const Card& other) const = 0;
        virtual InventoryHolder& operator-(const Card& other) const = 0;
};

#endif