#include "deckCard.hpp"

const int colorSize = 4;
const string colorList[colorSize] = {"Hijau", "Biru", "Kuning", "Merah"};

DeckCard::DeckCard() {
    this->cardList = {};
    for (int i = 1; i < 14; i++) {
        for (int j = 0; j < colorSize; j++) {
            double curValue = ((double) i / 10) + ((double) j * 3 / 100);
            Card temp(i, colorList[j], curValue);
            this->addCard(temp);
        }
    }
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

ostream& operator<<(ostream& os, const DeckCard& dc) {
    if (dc.cardList.size() == 0) {
        os << "Card is empty";
    } else {
        for (int i = 0; i < dc.cardList.size(); i++) {
            if (i != 0) {
                os << " ";
            }
            os << (dc.cardList).at(i);
        }
    }
    return os;
}