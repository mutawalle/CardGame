#include "playerCard.hpp"

template<class T>
PlayerCard<T>::PlayerCard() : InventoryHolder() {}

template<class T>
PlayerCard<T>::PlayerCard(vector<T> cl) : InventoryHolder(cl) {}

template<class T>
PlayerCard<T>::PlayerCard(const PlayerCard<T>& pc) : InventoryHolder(pc) {}

template<class T>
PlayerCard<T>::~PlayerCard() {
}

template<class T>
PlayerCard<T>& PlayerCard<T>::operator=(const PlayerCard<T>& other) {
    this->cardList = other.cardList;
}


template<class T>
void PlayerCard<T>::operator+(const T& other) {
    vector<Card>::iterator itr = find(this->cardList.begin(), this->cardList.end(), other);
    if (itr == this->cardList.end()) {
        cardList.push_back(other);
    }
}

template<class T>
void PlayerCard<T>::operator-(const T& other) {
    vector<Card>::iterator itr = find((this->cardList).begin(), (this->cardList).end(), other);
    if (itr != (this->cardList).end()) {
        (this->cardList).erase(itr);
    }
}