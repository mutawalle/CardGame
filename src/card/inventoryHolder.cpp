#include "inventoryHolder.hpp"
#include <iomanip>

map<string, string> colorsCode = {{"HIJAU", "\033[32m"}, {"BIRU", "\033[34m"}, {"KUNING", "\033[33m"}, {"MERAH", "\033[31m"}};

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

void InventoryHolder::printListCard(){
    int len = this->cardList.size();
    for(int i=0;i<len;i++){
        cout << colorsCode[this->cardList.at(i).getColor()] << "  -----  " << "\033[0m";
    }
    cout << endl;
    for(int i=0;i<len;i++){
        cout << colorsCode[this->cardList.at(i).getColor()] << " |" << left << setw(2) << this->cardList.at(i).getNumber() << "   | " << "\033[0m";
    }
    cout << endl;
    for(int i=0;i<len;i++){
        cout << colorsCode[this->cardList.at(i).getColor()] << " | / \\ | " << "\033[0m";
    }
    cout << endl;
    for(int i=0;i<len;i++){
        cout << colorsCode[this->cardList.at(i).getColor()] << " |  " << this->cardList.at(i).getColor()[0] << "  | " << "\033[0m";
    }
    cout << endl;
    for(int i=0;i<len;i++){
        cout << colorsCode[this->cardList.at(i).getColor()] << " | \\ / | " << "\033[0m";
    }
    cout << endl;
    for(int i=0;i<len;i++){
        cout << colorsCode[this->cardList.at(i).getColor()] << " |     | " << "\033[0m";
    }
    cout << endl;
    for(int i=0;i<len;i++){
        cout << colorsCode[this->cardList.at(i).getColor()] << "  -----  " << "\033[0m";
    }
    cout << endl;
}