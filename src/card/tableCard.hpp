// turunan dari InentoryHolder berupa list of card/vector of card
#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "inventoryHolder.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>

template <class T>
class TableCard: public virtual InventoryHolder<T> {

    public:
        TableCard();
        TableCard(vector<T>);
        TableCard(const TableCard<T>&);
        ~TableCard();
        virtual void operator+(const T&);
        virtual void operator-(const T&);

};

#endif