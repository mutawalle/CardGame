#include "tableCard.hpp"

TableCard::TableCard() {
    this->cardList = {};
}

TableCard::TableCard(vector<Card> cl) {
    this->cardList = cl;
}

TableCard::TableCard(const TableCard& pc) {
    this->cardList = pc.cardList;
}

TableCard::~TableCard() {
}

void TableCard::setCard(vector<Card> cl) {
    this->cardList = cl;
}

vector<Card> TableCard::getCard() {
    return this->cardList;
}

void TableCard::addCard(Card c) {
    cardList.push_back(c);
}

InventoryHolder& TableCard::operator+(const Card& other) const {
    TableCard *a = new TableCard(*this);
    a->addCard(other);
    return *a;
}

InventoryHolder& TableCard::operator-(const Card& other) const {
    TableCard *a = new TableCard(*this);
    vector<Card>::iterator itr;
    itr = find((a->getCard()).begin(), (a->getCard()).end(), other);
    if (itr != (a->getCard()).end()) {
        (a->cardList).erase(itr);
    }
    return *a;
}