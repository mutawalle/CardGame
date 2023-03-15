// turunan dari InentoryHolder berupa list of card/vector of card
#ifndef DECKCARD_HPP
#define DECKCARD_HPP

#include "inventoryHolder.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
template <class T>
class DeckCard: public virtual InventoryHolder<T> {

    public:
        DeckCard();
        DeckCard(vector<T>);
        DeckCard(const DeckCard<T>&);
        ~DeckCard();
        virtual void operator+(const T&);
        virtual void operator-(const T&);
};


#endif