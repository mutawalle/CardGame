#include "deckCard.hpp"

DeckCard::DeckCard() {
    this->cardList = {};
}

DeckCard::DeckCard(vector<Card> cl) {
    this->cardList = cl;
}

DeckCard::DeckCard(const DeckCard& pc) {
    this->cardList = pc.cardList;
}

DeckCard::~DeckCard() {
}

void DeckCard::setCard(vector<Card> cl) {
    this->cardList = cl;
}

vector<Card> DeckCard::getCard() {
    return this->cardList;
}

void DeckCard::addCard(Card c) {
    cardList.push_back(c);
}

InventoryHolder& DeckCard::operator+(const Card& other) const {
    DeckCard *a = new DeckCard(*this);
    a->addCard(other);
    return *a;
}

InventoryHolder& DeckCard::operator-(const Card& other) const {
    DeckCard *a = new DeckCard(*this);
    vector<Card>::iterator itr;
    itr = find((a->getCard()).begin(), (a->getCard()).end(), other);
    if (itr != (a->getCard()).end()) {
        (a->cardList).erase(itr);
    }
    return *a;
}