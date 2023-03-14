#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <bits/stdc++.h> 
#include "../game/gameState.hpp" 
#include "commandException.hpp"

#include "../ability/double.hpp"
#include "../ability/abillityless.hpp"
#include "../ability/half.hpp"
#include "../ability/next.hpp"
#include "../ability/quadruple.hpp"
#include "../ability/quarter.hpp"
#include "../ability/reRoll.hpp"
#include "../ability/reverse_direction.hpp"
#include "../ability/swap_card.hpp"
#include "../ability/switch.hpp"


using namespace std;

map<string, int> commands = {{"NEXT", 0}, {"HALF", 1}, {"DOUBLE", 2}, {"RE-ROLL", 3}, {"QUADRUPLE", 4}, {"QUARTER", 5}, {"REVERSE", 6}, {"SWAP",7}, {"SWITCH", 8}, {"ABILITYLESS", 9}};

class Command {
    private:
        GameState gameState;
        string command;
    public: 
        Command(GameState gameState){
            this->gameState = gameState;
        }

        void commandValidation(){
            cout<<"silahkan input command : ";
            cin >> command;
            cout << endl;
            auto In = commands.find(command);
            if(In == commands.end()){
                commandException err(command, " ", gameState.players.at(gameState.turn).getIsAbilityLess());
                throw err;
            }
            // bool isIn = false;
            // for(int i = 0; i < listCommand.size(); i++){
            //     if(command == listCommand[i]){
            //         isIn = true;
            //         break;
            //     }
            // }
            // if(!isIn){
            //     commandException err(command, " ");
            //     throw err;

            // }
        }
        void inputCommand(){
            bool valid = false;
            while(!valid){
                try{
                    commandValidation();
                    abillityValidation();
                    valid = true;
                }
                catch(commandException err){
                    err.errorMessage();
                }
            }
        }
        GameState getGamestate(){
            return gameState;
        }
        void setGameState(GameState gameState){
            this->gameState = gameState;
        }
        void abillityValidation(){
            switch (commands[this->command])
            {
            case 0:
            {
                Next next(this->gameState);
                next.DoAction();
                break;
            }
            case 1:
            {
                Double dble(this->gameState);
                dble.DoAction();
                break;
            }
            case 2:
            {
                Half half(this->gameState);
                half.DoAction();
                break;
            }
            case 3:
            {
                if(gameState.players.at(gameState.turn).getAbility() == "re-roll"){
                    ReRoll reRoll(this->gameState);
                    reRoll.DoAction();
                }
                else{
                    commandException err(" ", "re-roll", gameState.players.at(gameState.turn).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 4:
            {
                if(gameState.players.at(gameState.turn).getAbility() == "quadruple"){
                    Quadruple quadruple(this->gameState);
                    quadruple.DoAction();
                }
                else{
                    commandException err(" ", "quadruple", gameState.players.at(gameState.turn).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 5:
            {
                if(gameState.players.at(gameState.turn).getAbility() == "quarter"){
                    Quarter quarter(this->gameState);
                    quarter.DoAction();
                }
                else{
                    commandException err(" ", "quarter", gameState.players.at(gameState.turn).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 6:
            {
                if(gameState.players.at(gameState.turn).getAbility() == "reverseDirection"){
                    ReverseDirection reverseDirection(this->gameState);
                    reverseDirection.DoAction();
                }
                else{
                    commandException err(" ", "reverseDirection", gameState.players.at(gameState.turn).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 7:
            {
                if(gameState.players.at(gameState.turn).getAbility() == "swap-card"){
                    vector<Player> listTarget;
                    for(size_t i = 0; i<gameState.players.size(); i++){
                        if(i != gameState.turn){
                            listTarget.push_back(gameState.players[i]);
                        }
                    }
                    for(size_t i = 0; i<listTarget.size(); i++){
                        cout << i+1<< listTarget[i].getName()<<endl;
                    }
                    cout << gameState.players.at(gameState.turn).getName() << " akan melakukan swap"<< endl;
                    int noPlayer1, noPlayer2, noKartu1, noKartu2;
                    cout << "Masukkan nomor urut pemain pertama yang ingin ditukar" << endl;
                    cin >> noPlayer1;
                    while(noPlayer1 < 1 || noPlayer1 >6){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> noPlayer1;
                    }
                    listTarget.erase(listTarget.begin() + noPlayer1-1);
                    for(size_t i = 0; i<listTarget.size(); i++){
                        cout << i+1<< listTarget[i].getName()<<endl;
                    }
                    cout << "Masukkan nomor urut pemain kedua yang ingin ditukar" << endl;
                    cin >> noPlayer2;
                    while(noPlayer2 < 1 || noPlayer2 >6){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> noPlayer2;
                    }
                    cout << "Pilih kiri atau kanan dari pemain pertama" << endl;
                    cout << "1. Kanan"<<endl;
                    cout << "2. Kiri"<< endl;
                    cin >> noKartu1;
                    while(noKartu1 <1 && noKartu1 > 2){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> noKartu1;
                    }
                    cout << "Pilih kiri atau kanan dari pemain kedua" << endl;
                    cout << "1. Kanan"<<endl;
                    cout << "2. Kiri"<< endl;
                    cin >> noKartu2;
                    while(noKartu2 <1 && noKartu2 > 2){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> noKartu2;
                    }
                    SwapCard swapCard(this->gameState, noPlayer1-1, noPlayer2-1, noKartu1-1, noKartu2-1);
                    swapCard.DoAction();
                }
                else{
                    commandException err(" ", "swap-card", gameState.players.at(gameState.turn).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 8:
            {
                if(gameState.players.at(gameState.turn).getAbility() == "switch"){
                    int noPlayer;
                    vector<Player> listTarget;
                    cout << gameState.players.at(gameState.turn).getName() << " akan melakukan switch"<< endl;
                    cout << "Kartu sekarang adalah : "<< endl;
                    cout << gameState.players.at(gameState.turn).getPlayerCard().getCard()[0].getNumber() << " " <<gameState.players.at(gameState.turn).getPlayerCard().getCard()[0].getColor() << endl;
                    cout << gameState.players.at(gameState.turn).getPlayerCard().getCard()[1].getNumber() << " " <<gameState.players.at(gameState.turn).getPlayerCard().getCard()[1].getColor() << endl;
                    cout << "Masukkan no pemain yang akan ditukar dengan Anda" << endl;
                    for(size_t i = 0; i<gameState.players.size(); i++){
                        if(i != gameState.turn){
                            listTarget.push_back(gameState.players[i]);
                        }
                    }
                    for(size_t i = 0; i<listTarget.size(); i++){
                        cout << i+1<< listTarget[i].getName()<<endl;
                    }
                    cin >> noPlayer;
                    while(noPlayer < 1 || noPlayer >6){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> noPlayer;
                    }
                    Switch swit = Switch(this->gameState, noPlayer-1);
                    swit.DoAction();
                }
                else{
                    commandException err(" ", "switch", gameState.players.at(gameState.turn).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 9:
            {
                if(gameState.players.at(gameState.turn).getAbility() == "abilityLess"){
                    vector<Player> listTarget;
                    cout << gameState.players.at(gameState.turn).getName() << " akan mematikan kartu ablity lawan!"<< endl;
                    cout << "silahkan pilih nomor pemain yang ingin dimatikan!"<< endl;
                    for(size_t i = 0; i<gameState.players.size(); i++){
                        if(i != gameState.turn){
                            listTarget.push_back(gameState.players[i]);
                        }
                    }
                    for(size_t i = 0; i<listTarget.size(); i++){
                        cout << i+1<< listTarget[i].getName()<<endl;
                    }
                    int nomorTarget;
                    cin >> nomorTarget;
                    while(nomorTarget < 1 || nomorTarget >6){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> nomorTarget;
                    }

                    AbilityLess abilityLess = AbilityLess(this->gameState, nomorTarget-1);
                    abilityLess.DoAction(); 
                }
                else{
                    commandException err(" ", "abillityLess", gameState.players.at(gameState.turn).getIsAbilityLess());
                    throw err;
                }
                break;
            }

            default:
                break;
            }
        }
        
};

#endif