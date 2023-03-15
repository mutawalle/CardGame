#include "tableCard.hpp"

template <class T>
TableCard<T>::TableCard() : InventoryHolder() {}

template <class T>
TableCard<T>::TableCard(vector<T> cl) : InventoryHolder(cl) {}

template <class T>
TableCard<T>::TableCard(const TableCard<T>& pc) : InventoryHolder(pc) {}

template <class T>
TableCard<T>::~TableCard() {}

template <class T>
void TableCard<T>::operator+(const T& other) {
    vector<Card>::iterator itr = find(this->cardList.begin(), this->cardList.end(), other);
    if (itr == this->cardList.end()) {
        cardList.push_back(other);
    }
}

template <class T>
void TableCard<T>::operator-(const T& other) {
    vector<Card>::iterator itr = find((this->cardList).begin(), (this->cardList).end(), other);
    if (itr != (this->cardList).end()) {
        (this->cardList).erase(itr);
    }
}