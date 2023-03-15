#include "deckCard.hpp"

using namespace std;

map<string, int> colorsDeckCard = {{"HIJAU", 0}, {"BIRU", 1}, {"KUNING", 2}, {"MERAH", 3}};

const int colorSize = colorsDeckCard.size();

template <class T>
DeckCard<T>::DeckCard() {
    this->cardList = {};
    int n;
    cout << "Masukkan jumlah kartu yang ingin dimasukkan ke dalam deck: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        T temp;
        cin >> temp;
        this->cardList.push_back(temp);
    }
}

template <>
DeckCard<Card>::DeckCard() {
    this->cardList = {};
    for (int i = 1; i < 14; i++) {
        for (int j = 0; j < colorSize; j++) {
            double curValue = ((double) i / 10) + ((double) j * 3 / 100);
            Card temp(i, next(colorsDeckCard.begin(),j)->first, curValue);
            this->cardList.push_back(temp);
        }
    }
}

template <class T>
DeckCard<T>::DeckCard(vector<T> cl) : InventoryHolder(cl){
}

template <class T>
DeckCard<T>::DeckCard(const DeckCard<T>& pc) : InventoryHolder(pc){
}

template <class T>
DeckCard<T>::~DeckCard() {
}

template <class T>
void DeckCard<T>::operator+(const T& other) {
    auto itr = find((this->cardList).begin(), (this->cardList).end(), other);
    if (itr == (this->cardList).end()) {
        this->cardList.push_back(other);
    }
}

template <class T>
void DeckCard<T>::operator-(const T& other) {
    auto itr = find((this->cardList).begin(), (this->cardList).end(), other);
    if (itr != (this->cardList).end()) {
        (this->cardList).erase(itr);
    }
}