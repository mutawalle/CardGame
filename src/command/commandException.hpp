#ifndef COMMANDEXCEPTION_HPP
#define COMMANDEXCEPTION_HPP


#include <bits/stdc++.h>
using namespace std;
class commandException{
    private:
        string commandInputed;
        string abillity;
    public:
        commandException(string commandInputed, string abillity){
            this->commandInputed = commandInputed;
            this->abillity = abillity;
        }
        void errorMessage(){
            if(commandInputed != " "){
                cout << commandInputed << " tidak ada dalam daftar perintah!!"<< endl;
                cout << "silahkan input lagi!"<<endl;
            }
            else if(abillity != " "){
                cout << abillity << " tidak dimiliki oleh player!"<< endl;
                cout << "silahkan input lagi!"<<endl;
            }
        }

};

#endif