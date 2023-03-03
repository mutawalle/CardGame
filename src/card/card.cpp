#include "card.hpp"

Card::Card() {
    this->number = 0;
    this->color = "";
    this->value = 0;
}

Card::Card(int number, string color, double value) {
    this->number = number;
    this->color = color;
    this->value = value;
}

Card::Card(const Card& other) {
    this->number = other.number;
    this->color = other.color;
    this->value = other.value;
}

Card& Card::operator=(const Card& other) {
    this->number = other.number;
    this->color = other.color;
    this->value = other.value;
}

Card::~Card() {
}

double Card::getValue() const  {
    return this->value;
}

int Card::getNumber() const {
    return this->number;
}