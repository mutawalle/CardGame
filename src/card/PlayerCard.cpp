#include "PlayerCard.hpp"

PlayerCard::PlayerCard() {
    this->cardList = {};
}

PlayerCard::PlayerCard(vector<Card> cl) {
    this->cardList = cl;
}

PlayerCard::PlayerCard(const PlayerCard& pc) {
    this->cardList = pc.cardList;
}

PlayerCard::~PlayerCard() {
}

void PlayerCard::setCard(vector<Card> cl) {
    this->cardList = cl;
}

vector<Card> PlayerCard::getCard() {
    return this->cardList;
}

void PlayerCard::addCard(Card c) {
    cardList.push_back(c);
}

InventoryHolder& PlayerCard::operator+(const Card& other) const {
    PlayerCard *a = new PlayerCard(*this);
}