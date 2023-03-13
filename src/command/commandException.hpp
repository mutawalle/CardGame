#ifndef COMMANDEXCEPTION_HPP
#define COMMANDEXCEPTION_HPP


#include <bits/stdc++.h>
using namespace std;
class commandException{
    private:
        string commandInputed;
        string abillity;
        bool abilityLess;
    public:
        commandException(string commandInputed, string abillity, bool abilityLess){
            this->commandInputed = commandInputed;
            this->abillity = abillity;
            this->abilityLess = abilityLess;
        }
        void errorMessage(){
            if(commandInputed != " "){
                cout << commandInputed << " tidak ada dalam daftar perintah!!"<< endl;
                cout << "silahkan input lagi!"<<endl;
            }
            else if(abillity != " "){
                if(abilityLess == true){
                    cout << "kartu " << abillity << " telah dimatikan"<<endl;
                    cout << "silahkan masukkan perintah lainnya!"<<endl;
                }
                else{
                    cout << abillity << " tidak dimiliki oleh player!"<< endl;
                    cout << "silahkan input lagi!"<<endl;
                }
            }
        }

};

#endif