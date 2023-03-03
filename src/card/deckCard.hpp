// turunan dari InentoryHolder berupa list of card/vector of card
#ifndef DECKCARD_HPP
#define DECKCARD_HPP

#include "inventoryHolder.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class DeckCard: public InventoryHolder {

    private:
        vector<Card> cardList;

    public:
        DeckCard();
        DeckCard(vector<Card>);
        DeckCard(const DeckCard&);
        ~DeckCard();
        void setCard(vector<Card>);
        vector<Card> getCard();
        void addCard(Card);
        virtual InventoryHolder& operator+(const Card& other) const override;
        virtual InventoryHolder& operator-(const Card& other) const override;
        friend ostream& operator<<(ostream&, const DeckCard&);
};

#endif