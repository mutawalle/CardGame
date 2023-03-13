#include "player.hpp"
#include <bits/stdc++.h>

using namespace std;

int main(){
    Card c1(10, "Hijau");
    Card c2(11, "Merah");
    Card c3(12, "Biru");
    Card c4(13, "Merah");
    Card c5(9, "Merah");
    vector<Card> vc;
    vc.push_back(c1);
    vc.push_back(c2);
    vc.push_back(c3);
    vc.push_back(c4);
    vc.push_back(c5);   
    
    Player test("konzz", vc, "", 0);
    Card c = test.getHighCard();
    cout << c.getNumber();
}