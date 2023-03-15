#ifndef INVENTORYHOLDER_CPP
#define INVENTORYHOLDER_CPP

#include "inventoryHolder.hpp"

template <class T>
InventoryHolder<T>::InventoryHolder() : cardList({}) {}

template <class T>
InventoryHolder<T>::InventoryHolder(vector<T> cl) : cardList(cl) {}

template <class T>
InventoryHolder<T>::InventoryHolder(const InventoryHolder<T>& other) : cardList(other.cardList) {}

template <class T>
InventoryHolder<T>::~InventoryHolder() {}

template <class T>
void InventoryHolder<T>::setCard(vector<T> cl) {
    this->cardList = cl;
}

template <class T>
vector<T>& InventoryHolder<T>::getCard() {
    return this->cardList;
}

template <class T>
size_t InventoryHolder<T>::getCardListLength() {
    return this->cardList.size();
}

template <class T>
ostream& operator<<(ostream& os, const InventoryHolder<T>& dc) {
    if (dc.cardList.size() == 0) {
        os << "Card is empty";
    } else {
        for (size_t i = 0; i < dc.cardList.size(); i++) {
            if (i != 0) {
                os << " ";
            }
            os << (dc.cardList).at(i);
        }
    }
    return os;
}

#endif
