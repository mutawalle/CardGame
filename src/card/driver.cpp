#include "deckCard.hpp"
#include "playerCard.hpp"
#include "tableCard.hpp"
#include "card.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    Card c(15, "Hijau", 0.1), d(2, "Merah"), e(3, "Kuning");
    vector<Card> mc = {d, e, c};
    for (int i = 0; i < 3; i++) {
        cout << mc[i] << " ";
    }
    cout << endl;
    sort(mc.begin(), mc.end());
    for (int i = 0; i < 3; i++) {
        cout << mc[i] << " ";
    }
    cout << endl;
    // DeckCard a;
    // a - d;
    // a - e;
    // a + e;
    // cout << a << endl;
    // PlayerCard pc;
    // pc + e;
    // pc + d;
    // pc - d;
    // cout << pc << endl;
    // TableCard tc;
    // tc + e;
    // tc + d;
    // tc - d;
    // cout << tc << endl;

    return 0;
}