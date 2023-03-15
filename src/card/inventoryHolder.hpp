// class abstrak untuk diturunkan menjadi PlayerCard,DeckCard, dan TableCard
#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include "card.hpp"
#include <vector>
#include <iostream>

using namespace std;


template <class T>
class InventoryHolder {
    protected:
        vector<T> cardList;

    public:
        InventoryHolder();
        InventoryHolder(vector<T>);
        InventoryHolder(const InventoryHolder<T>&);
        ~InventoryHolder();
        void setCard(vector<T>);
        vector<T>& getCard();
        size_t getCardListLength();
        friend ostream& operator<<(ostream&, const InventoryHolder<T>&);
        virtual void operator+(const T& other) = 0;
        virtual void operator-(const T& other) = 0;
};

#endif