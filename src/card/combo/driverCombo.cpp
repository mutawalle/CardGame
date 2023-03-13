#include "../card.hpp"
#include "Pair.hpp"
#include <bits/stdc++.h>
using namespace std ;

int main(){
    Card c1(13,"Hijau");
    Card c2(13,"Merah");
    vector<Card> card;
    card.push_back(c1);
    card.push_back(c2);
    PairCombo cc(card);
    cout<<cc.getValue()<<endl;
}
//g++ driverCombo.cpp ../card.cpp -o driver