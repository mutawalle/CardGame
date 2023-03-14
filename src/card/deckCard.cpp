#include "deckCard.hpp"
#include "../enum/colors.hpp"

using namespace std;

const int colorSize = colors.size();

DeckCard::DeckCard() {
    this->cardList = {};
    for (int i = 1; i < 14; i++) {
        for (int j = 0; j < colorSize; j++) {
            double curValue = ((double) i / 10) + ((double) j * 3 / 100);
            Card temp(i, next(colors.begin(),j)->first, curValue);
            this->cardList.push_back(temp);
        }
    }
}

DeckCard::DeckCard(vector<Card> cl) : InventoryHolder(cl){
}

DeckCard::DeckCard(const DeckCard& pc) : InventoryHolder(pc){
}

DeckCard::~DeckCard() {
}

void DeckCard::operator+(const Card& other) {
    auto itr = find((this->cardList).begin(), (this->cardList).end(), other);
    if (itr == (this->cardList).end()) {
        this->cardList.push_back(other);
    }
}

void DeckCard::operator-(const Card& other) {
    auto itr = find((this->cardList).begin(), (this->cardList).end(), other);
    if (itr != (this->cardList).end()) {
        (this->cardList).erase(itr);
    }
}