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
    string numString, colString;
    numString = to_string(obj.getNumber());
    if (obj.getNumber() < 10) {
        numString += " ";
    }

    if (obj.getColor() == "HIJAU" || obj.getColor() == "Keriting") {
        colString = "H";
    } else if (obj.getColor() == "BIRU" || obj.getColor() == "Sekop") {
        colString = "B";
    } else if (obj.getColor() == "MERAH" || obj.getColor() == "Wajik") {
        colString = "M";
    } else if (obj.getColor() == "YELLOW" || obj.getColor() == "Hati") {
        colString = "Y";
    }
    cout << " _____" << endl;
    cout << "|" << numString << "   |" << endl;
    cout << "| / \\ |" << endl;
    cout << "|  " << colString << "  |" << endl;
    cout << "| \\ / |" << endl;
    cout << "|_____|" << endl;

    return os;
}

bool Card::operator==(const Card& other) {
    return this->getValue() == other.getValue() && this->getColor() == other.getColor() && this->getNumber() == other.getNumber();
}