#include "PlayerCard.hpp"

PlayerCard::PlayerCard() : InventoryHolder() {}

PlayerCard::PlayerCard(vector<Card> cl) : InventoryHolder(cl) {}

PlayerCard::PlayerCard(const PlayerCard& pc) : InventoryHolder(pc) {}

PlayerCard::~PlayerCard() {
}

void PlayerCard::operator+(const Card& other) {
    vector<Card>::iterator itr = find(this->cardList.begin(), this->cardList.end(), other);
    if (itr == this->cardList.end()) {
        cardList.push_back(other);
    }
}

void PlayerCard::operator-(const Card& other) {
    vector<Card>::iterator itr = find((this->cardList).begin(), (this->cardList).end(), other);
    if (itr != (this->cardList).end()) {
        (this->cardList).erase(itr);
    }
}