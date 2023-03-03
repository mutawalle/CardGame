#include "deckCard.hpp"
#include "card.hpp"
#include <iostream>

using namespace std;

int main() {

    Card c(1, "Hijau", 0.1);
    DeckCard dc;
    cout << dc << endl;

    return 0;
}