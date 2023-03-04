// turunan dari InentoryHolder berupa list of card/vector of card
#ifndef DECKCARD_HPP
#define DECKCARD_HPP

#include "inventoryHolder.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class DeckCard: public virtual InventoryHolder {

    public:
        DeckCard();
        DeckCard(vector<Card>);
        DeckCard(const DeckCard&);
        ~DeckCard();
        virtual void operator+(const Card&);
        virtual void operator-(const Card&);
};

#endif