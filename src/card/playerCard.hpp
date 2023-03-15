// turunan dari InventoryHolder berupa list of card/pair card karena kaatu player selalu 2
#ifndef PLAYERCARD_HPP
#define PLAYERCARD_HPP

#include "inventoryHolder.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>

template <class T>
class PlayerCard: public virtual InventoryHolder<T> {

    public:
        PlayerCard();
        PlayerCard(vector<T>);
        PlayerCard(const PlayerCard<T>&);
        ~PlayerCard();
        PlayerCard<T>& operator=(const PlayerCard<T>&);
        virtual void operator+(const T&);
        virtual void operator-(const T&);
};

#endif