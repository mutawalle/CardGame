#include "GameStateBj.hpp"


class GameBJ{
   private:
       BlackJack state;
       bool status;
       int point;
       string name;
  
   public:
       GameBJ(){
           status = true;
           point = 1000;
           cout << "Masukan Namamu : " ;
           cin >> name;
           state.getPlayerBj().setName(name);
           state.getPlayerBj().setPoint(point);
        //    cout << "Poin awal mu: " << point << endl;
       }


       void startGame(){
           while(status){
            cout << "Poin mu sekarang : " << point << endl;
               cout << "Masukan bid mu: " ;
               int bid;
               cin >> bid;
               bool stat = true;
               if(bid <= state.getPlayerBj().getPoint()){
                   stat = false;
               }else{
                   cout << "masukan salah" << endl;
               }
               while(stat){
                    cout << "Poin mu sekarang: " << point << endl;
                    cout << "Masukan bid mu: ";
                    cin >> bid;
                    stat = true;
                    if(bid <= state.getPlayerBj().getPoint()){
                        stat = false;
                    }else{
                        cout << "masukan salah" << endl;
                    }
               }
               state.start();
               if(state.getWin()){
                   point = state.getPlayerBj().getPoint() + bid;
                   state.getPlayerBj().setPoint(point);
               }else{
                   point = state.getPlayerBj().getPoint() - bid;
                   state.getPlayerBj().setPoint(point);
               }
               if(state.getPlayerBj().getPoint() != 0){
                   cout<<"mau main lagi: ya/tidak ";
                   string input;
                   cin >> input;
                   if(input == "tidak"){
                       break;
                   }else{
                       state = BlackJack( );
                       state.getPlayerBj().setName(name);
                       state.getPlayerBj().setPoint(point);
                      
                   }
               }else{
                   break;
               }
           }
           cout << "Poin mu: " << point << endl;
       }
};
