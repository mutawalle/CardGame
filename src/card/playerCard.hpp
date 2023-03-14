// turunan dari InventoryHolder berupa list of card/pair card karena kaatu player selalu 2
#ifndef PLAYERCARD_HPP
#define PLAYERCARD_HPP

#include "inventoryHolder.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>

class PlayerCard: public virtual InventoryHolder {

    public:
        PlayerCard();
        PlayerCard(vector<Card>);
        PlayerCard(const PlayerCard&);
        ~PlayerCard();
        PlayerCard& operator=(const PlayerCard&);
        virtual void operator+(const Card&);
        virtual void operator-(const Card&);
};

#endif