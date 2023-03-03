// turunan dari InentoryHolder berupa list of card/vector of card
#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "inventoryHolder.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>

class TableCard: public InventoryHolder {

    private:
        vector<Card> cardList;

    public:
        TableCard();
        TableCard(vector<Card>);
        TableCard(const TableCard&);
        ~TableCard();
        void setCard(vector<Card>);
        vector<Card> getCard();
        void addCard(Card);
        virtual InventoryHolder& operator+(const Card& other) const override;
        virtual InventoryHolder& operator-(const Card& other) const override;

};

#endif