#include "inventoryHolder.hpp"

InventoryHolder::InventoryHolder() : cardList({}) {}

InventoryHolder::InventoryHolder(vector<Card> cl) : cardList(cl) {}

InventoryHolder::InventoryHolder(const InventoryHolder& other) : cardList(other.cardList) {}

InventoryHolder::~InventoryHolder() {}

void InventoryHolder::setCard(vector<Card> cl) {
    this->cardList = cl;
}

vector<Card>& InventoryHolder::getCard() {
    return this->cardList;
}

size_t InventoryHolder::getCardListLength() {
    return this->cardList.size();
}

ostream& operator<<(ostream& os, const InventoryHolder& dc) {
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