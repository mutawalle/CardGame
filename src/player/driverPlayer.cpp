// #include "player.hpp"
// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     Card c1(4, "Hijau");
//     Card c2(4, "Merah");
//     Card c3(4, "Biru");
//     Card c4(4, "Kuning");
//     Card c6(3, "Hijau");
//     Card c5(3, "Kuning");
//     Card c7(3,"Biru");
//     vector<Card> vc;
//     vc.push_back(c1);
//     vc.push_back(c2);
//     vc.push_back(c3);
//     vc.push_back(c4);
//     vc.push_back(c5);   
//     vc.push_back(c6);   
//     vc.push_back(c7);   
    
//     Player test("konzz", vc, "", 0);
//     test.sorting();
//     cout<<test.getPlayerCard();
//     cout<<endl;
//     Card c = test.getHighCard();

//     vector<Card> temp=test.value();
    
//     if(temp.empty()){
//         cout<<"kosong\n\n";
//     }
//     cout<<"hasil kartu\n";
//     for(int i=0;i<temp.size();i++){
//         cout << temp[i] << endl;
//     }

//     // cout << c.getNumber();
// }
// // g++ driverPlayer.cpp player.hpp -o main ../card/card.cpp ../card/playerCard.cpp ../card/inventoryHolder.cpp ../card/abstractValue.hpp