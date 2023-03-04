// turunan dari InentoryHolder berupa list of card/vector of card
#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "inventoryHolder.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>

class TableCard: public virtual InventoryHolder {

    public:
        TableCard();
        TableCard(vector<Card>);
        TableCard(const TableCard&);
        ~TableCard();
        virtual void operator+(const Card&);
        virtual void operator-(const Card&);

};

#endif