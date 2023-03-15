#include "card.hpp"

map<string, int> colorsCard = {{"HIJAU", 0}, {"BIRU", 1}, {"KUNING", 2}, {"MERAH", 3}};
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

Card::Card(int number, string color) {
    this->number = number;
    this->color = color;
    double toValue = (double) number / 10 + colorsCard[color] * 3 / 100;
    this->value = toValue;
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
    return *this;
}

Card::~Card() {
}

double Card::getValue() const  {
    return this->value;
}

int Card::getNumber() const {
    return this->number;
}

string Card::getColor() const {
    return this->color;
}

ostream& operator<<(ostream& os, const Card& obj) {
    os << "{" << obj.getNumber() << " " << obj.getColor() << " " << obj.getValue() << "}";
    return os;
}