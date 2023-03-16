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
        // Baris paling atas
        for (size_t i = 0; i < dc.cardList.size(); i++) {
            if (dc.cardList.at(i).getColor() == "HIJAU" || dc.cardList.at(i).getColor() == "Keriting") {
                cout << "\033[32m";
            } else if (dc.cardList.at(i).getColor() == "BIRU" || dc.cardList.at(i).getColor() == "Sekop") {
                cout << "\033[34m";
            } else if (dc.cardList.at(i).getColor() == "MERAH" || dc.cardList.at(i).getColor() == "Wajik") {
                cout << "\033[31m";
            } else if (dc.cardList.at(i).getColor() == "YELLOW" || dc.cardList.at(i).getColor() == "Hati") {
                cout << "\033[33m";
            }
            cout << " _____ ";
            cout << "\033[0m";
        }
        cout << endl;
        // Baris kedua
        string numString, colString;
        for (size_t i = 0; i < dc.cardList.size(); i++) {
            numString = to_string(dc.cardList.at(i).getNumber());
            if (dc.cardList.at(i).getColor() == "HIJAU" || dc.cardList.at(i).getColor() == "Keriting") {
                cout << "\033[32m";
            } else if (dc.cardList.at(i).getColor() == "BIRU" || dc.cardList.at(i).getColor() == "Sekop") {
                cout << "\033[34m";
            } else if (dc.cardList.at(i).getColor() == "MERAH" || dc.cardList.at(i).getColor() == "Wajik") {
                cout << "\033[31m";
            } else if (dc.cardList.at(i).getColor() == "YELLOW" || dc.cardList.at(i).getColor() == "Hati") {
                cout << "\033[33m";
            }
            if (dc.cardList.at(i).getNumber() < 10) {
                numString += " ";
            }
            cout << "|" << numString << "   |";
            cout << "\033[0m";
        }
        cout << endl;
        // Baris ketiga
        for (size_t i = 0; i < dc.cardList.size(); i++) {
            if (dc.cardList.at(i).getColor() == "HIJAU" || dc.cardList.at(i).getColor() == "Keriting") {
                cout << "\033[32m";
            } else if (dc.cardList.at(i).getColor() == "BIRU" || dc.cardList.at(i).getColor() == "Sekop") {
                cout << "\033[34m";
            } else if (dc.cardList.at(i).getColor() == "MERAH" || dc.cardList.at(i).getColor() == "Wajik") {
                cout << "\033[31m";
            } else if (dc.cardList.at(i).getColor() == "YELLOW" || dc.cardList.at(i).getColor() == "Hati") {
                cout << "\033[33m";
            }
            cout << "| / \\ |";
            cout << "\033[0m";
        }
        cout << endl;
        for (size_t i = 0; i < dc.cardList.size(); i++) {
            if (dc.cardList.at(i).getColor() == "HIJAU" || dc.cardList.at(i).getColor() == "Keriting") {
                cout << "\033[32m";
                colString = "H";
            } else if (dc.cardList.at(i).getColor() == "BIRU" || dc.cardList.at(i).getColor() == "Sekop") {
                cout << "\033[34m";
                colString = "B";
            } else if (dc.cardList.at(i).getColor() == "MERAH" || dc.cardList.at(i).getColor() == "Wajik") {
                cout << "\033[31m";
                colString = "M";
            } else if (dc.cardList.at(i).getColor() == "YELLOW" || dc.cardList.at(i).getColor() == "Hati") {
                cout << "\033[33m";
                colString = "Y";
            }
            cout << "|  " << colString << "  |";
            cout << "\033[0m";
        }
        cout << endl;
        // Baris kelima
        for (size_t i = 0; i < dc.cardList.size(); i++) {
            if (dc.cardList.at(i).getColor() == "HIJAU" || dc.cardList.at(i).getColor() == "Keriting") {
                cout << "\033[32m";
                colString = "H";
            } else if (dc.cardList.at(i).getColor() == "BIRU" || dc.cardList.at(i).getColor() == "Sekop") {
                cout << "\033[34m";
                colString = "B";
            } else if (dc.cardList.at(i).getColor() == "MERAH" || dc.cardList.at(i).getColor() == "Wajik") {
                cout << "\033[31m";
                colString = "M";
            } else if (dc.cardList.at(i).getColor() == "YELLOW" || dc.cardList.at(i).getColor() == "Hati") {
                cout << "\033[33m";
                colString = "Y";
            }
            cout << "| \\ / |";
            cout << "\033[0m";
        }
        cout << endl;
        // Baris keenam
        for (size_t i = 0; i < dc.cardList.size(); i++) {
            if (dc.cardList.at(i).getColor() == "HIJAU" || dc.cardList.at(i).getColor() == "Keriting") {
                cout << "\033[32m";
                colString = "H";
            } else if (dc.cardList.at(i).getColor() == "BIRU" || dc.cardList.at(i).getColor() == "Sekop") {
                cout << "\033[34m";
                colString = "B";
            } else if (dc.cardList.at(i).getColor() == "MERAH" || dc.cardList.at(i).getColor() == "Wajik") {
                cout << "\033[31m";
                colString = "M";
            } else if (dc.cardList.at(i).getColor() == "YELLOW" || dc.cardList.at(i).getColor() == "Hati") {
                cout << "\033[33m";
                colString = "Y";
            }
            cout << "|_____|";
            cout << "\033[0m";
        }
        cout << endl;
    }
    return os;
}