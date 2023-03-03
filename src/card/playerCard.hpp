// turunan dari InventoryHolder berupa list of card/pair card karena kaatu player selalu 2
#ifndef PLAYERCARD_HPP
#define PLAYERCARD_HPP

#include "inventoryHolder.hpp"
#include "card.hpp"
#include <vector>

class PlayerCard: public InventoryHolder {

    private:
        vector<Card> cardList;

    public:
        PlayerCard();
        PlayerCard(vector<Card>);
        PlayerCard(const PlayerCard&);
        ~PlayerCard();
        void setCard(vector<Card>);
        vector<Card> getCard();
        void addCard(Card);
        virtual InventoryHolder& operator+(const Card& other) const override;
        virtual InventoryHolder& operator-(const Card& other) const override;
};

#endif