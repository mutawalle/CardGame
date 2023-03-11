#include "tableCard.hpp"

TableCard::TableCard() : InventoryHolder() {}

TableCard::TableCard(vector<Card> cl) : InventoryHolder(cl) {}

TableCard::TableCard(const TableCard& pc) : InventoryHolder(pc) {}

TableCard::~TableCard() {}

void TableCard::operator+(const Card& other) {
    vector<Card>::iterator itr = find(this->cardList.begin(), this->cardList.end(), other);
    if (itr == this->cardList.end()) {
        cardList.push_back(other);
    }
}

void TableCard::operator-(const Card& other) {
    vector<Card>::iterator itr = find((this->cardList).begin(), (this->cardList).end(), other);
    if (itr != (this->cardList).end()) {
        (this->cardList).erase(itr);
    }
}