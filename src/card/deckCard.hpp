// turunan dari InentoryHolder berupa list of card/vector of card
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
};

#endif