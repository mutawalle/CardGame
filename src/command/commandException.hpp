#ifndef COMMANDEXCEPTION_HPP
#define COMMANDEXCEPTION_HPP


#include <bits/stdc++.h>
using namespace std;
class commandException{
    private:
        string commandInputed;
        string abillity;
        GameState gameState;
    public:
        commandException(string commandInputed, string abillity, GameState gameState){
            this->commandInputed = commandInputed;
            this->abillity = abillity;
            this->gameState = gameState;
        }
        void errorMessage(){
            if(commandInputed != " "){
                cout << commandInputed << " tidak ada dalam daftar perintah!!"<< endl;
                cout << "silahkan input lagi!"<<endl;
            }
            else if(abillity != " "){
                if(gameState.players.at(gameState.order.at(this->gameState.turn)).getIsAbilityLess()){
                    if(gameState.players.at(gameState.order.at(this->gameState.turn)).getAbility() == abillity){
                        cout << "kartu " << abillity << " telah dimatikan"<<endl;
                        cout << "silahkan masukkan perintah lainnya!"<<endl;
                    }
                    else{
                        cout << abillity << " tidak dimiliki oleh player!"<< endl;
                        cout << "silahkan input lagi!"<<endl;
                    }
                }
                else{
                    cout << abillity << " tidak dimiliki oleh player!"<< endl;
                    cout << "silahkan input lagi!"<<endl;
                }
            }
        }

};

#endif