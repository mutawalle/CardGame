#include "../player/player.hpp"
#include "../card/deckCard.hpp"
#include "../card/playerCard.hpp"
#include <iostream>
#include <time.h>
using namespace std;


class BlackJack {
 public :
   BlackJack(){
       this->bandar = Player();
       this->player2 = Player();
       vector<Card> nama;
       string nama1[] = {"Wajik","Keriting","Hati","Sekop"};
       for(int i = 0;i<4;i++){
           for(int j = 1 ; j <= 13 ; j++){
               if(j == 11 || j == 12 || j == 13){
                   nama.push_back(Card(j,nama1[i],10));
               }else{
                   nama.push_back(Card(j,nama1[i],j));
               }
           }
       }
       this->deckCard = DeckCard(nama);
       bandar.setName("Bandar");
       status = true;
       win = false;
   }


   void getCardPlayer(){
       srand(time(nullptr));
       int randVal = rand() % deckCard.getCard().size();
       Card tmp = this->deckCard.getCard()[randVal];
       PlayerCard playerCard = this->player2.getPlayerCard();
       playerCard + tmp;
       this->deckCard - tmp;
       this->player2.setPlayerCard(playerCard);
   }


   void getCardBandar(){
       srand(time(nullptr));
       int randVal = rand() % deckCard.getCard().size();
       Card tmp = this->deckCard.getCard()[randVal];
       PlayerCard playerCard = this->bandar.getPlayerCard();
       playerCard + tmp;
       this->deckCard - tmp;
       this->bandar.setPlayerCard(playerCard);
   }


   void hit(){
       double val;
       this->getCardPlayer();
       evaluate(player2,val);
       if(val == 21){
           status = false;
           win = true;
       }else if(val > 21){
           status = false;
       }else{
           /* biarkan kosong */
       }      
       cout << endl;
       
       cout << "Dealer card:" << endl;
       cout << " _____" << endl;
       cout << "|??   |" << endl;
       cout << "| / \\ |" << endl;
       cout << "|  ?  |" << endl;
       cout << "| \\ / |" << endl;
       cout << "|_____|" << endl;
       cout << bandar.getPlayerCard().getCard().at(1);
       cout << endl;
       cout << "Player card:" << endl;
       cout << this->player2.getPlayerCard();
   }


   void evaluate(Player& other,double& val){
       vector<Card> temp =  other.getPlayerCard().getCard();
       double value = 0;
       bool isAs = false;
       for (size_t i = 0 ; i<temp.size();i++){
           if(temp.at(i).getNumber() == 1){
               isAs = true;
           }
           value = value + temp.at(i).getValue();
       }


       if(value <= 11 && isAs){
           value = value + 10;
       }
       val = value;
   }


   void stand(){
       this->status = false;
       double bandarVal;
       double playerVal;
       evaluate(player2 ,playerVal);
       evaluate(bandar,bandarVal);
       while(bandarVal < 21  && bandarVal <= playerVal){
           getCardBandar();
           evaluate(bandar, bandarVal);
       }
       if(bandarVal > 21){
           win = true;
       }
        cout << endl;
       cout << "Dealer card:" << endl;
       cout << " _____" << endl;
       cout << "|??   |" << endl;
       cout << "| / \\ |" << endl;
       cout << "|  ?  |" << endl;
       cout << "| \\ / |" << endl;
       cout << "|_____|" << endl;
       cout << bandar.getPlayerCard().getCard().at(1);
       cout << endl;
       cout << "Player card:" << endl;
       cout << this->player2.getPlayerCard();

   }


   void start(){
       getCardBandar();
       getCardBandar();
       getCardPlayer();
       getCardPlayer();
       cout << endl;
       cout << "Dealer card:" << endl;
       cout << " _____" << endl;
       cout << "|??   |" << endl;
       cout << "| / \\ |" << endl;
       cout << "|  ?  |" << endl;
       cout << "| \\ / |" << endl;
       cout << "|_____|" << endl;
       if (bandar.getPlayerCard().getCard().at(1).getColor() == "HIJAU" || bandar.getPlayerCard().getCard().at(1).getColor() == "Keriting") {
            cout << "\033[32m";
        } else if (bandar.getPlayerCard().getCard().at(1).getColor() == "BIRU" || bandar.getPlayerCard().getCard().at(1).getColor() == "Sekop") {
            cout << "\033[34m";
        } else if (bandar.getPlayerCard().getCard().at(1).getColor() == "MERAH" || bandar.getPlayerCard().getCard().at(1).getColor() == "Wajik") {
            cout << "\033[31m";
        } else if (bandar.getPlayerCard().getCard().at(1).getColor() == "YELLOW" || bandar.getPlayerCard().getCard().at(1).getColor() == "Hati") {
            cout << "\033[33m";
        }
       cout << bandar.getPlayerCard().getCard().at(1);
       cout << "\033[0m";
       cout << endl;
       cout << "Player card:" << endl;
       cout << this->player2.getPlayerCard();

      
       while(this->status){
            double valP;
            double valB;
            evaluate(player2, valP);
            evaluate(bandar, valB);
            cout<< "Nilai kartumu sebesar "<< valP<<endl;
            cout << "1. hit" << endl;
            cout << "2. stand" << endl << "ketik hit/stand: ";
            string input;
            cin >> input;
            if(input == "hit"){
                hit();
            }else if(input == "stand"){
                stand();
                
            }else{
                cout << "salah input" << endl;
            }
       }
       if(win){
           cout << "cie menang" << endl;
       }else{
           cout << "yah kalah.." << endl;
       }


   }
   Player& getPlayerBj(){
       return player2;
   }
   bool getWin(){
       return win;
   }
   private:
       Player bandar;
       Player player2;
       DeckCard deckCard;
       bool win;
       bool status;
       int points;


};

