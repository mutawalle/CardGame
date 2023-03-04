// class abstrak untuk diturunkan menjadi PlayerCard dan DeckCard
#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include "card.hpp"
#include <vector>
#include <iostream>

using namespace std;

class InventoryHolder {
    protected:
        vector<Card> cardList;
        InventoryHolder();
        InventoryHolder(vector<Card>);
        InventoryHolder(const InventoryHolder&);
        ~InventoryHolder();

    public:
        void setCard(vector<Card>);
        vector<Card> getCard();
        size_t getCardListLength();
        friend ostream& operator<<(ostream&, const InventoryHolder&);
        virtual void operator+(const Card& other) = 0;
        virtual void operator-(const Card& other) = 0;
};

#endif