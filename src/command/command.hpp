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

map<string, int> listCommand = {{"RE-ROLL", 3}, {"QUADRUPLE", 4}, {"QUARTER", 5}, {"REVERSE", 6}, {"SWAP",7}, {"SWITCH", 8}, {"ABILITYLESS", 9},
                                {"NEXT", 0}, {"DOUBLE", 2}, {"HALF", 1}};
// vector<string> listCommand = {"re-roll", "quadruple", "quarter", "reverse", "swap", "switch", "abilityless", "next", "double", "half"};
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
            auto In = listCommand.find(command);
            if(In == listCommand.end()){
                commandException err(command, " ");
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
            switch (listCommand[command])
            {
            case 0:
                Next next = Next(this->gameState);
                next.DoAction();
                break;
            case 1:
                Double dble = Double(this->gameState);
                dble.DoAction();
                break;
            case 2:
                Half half = Half(this->gameState);
                half.DoAction();
                break;
            case 3:
                if(gameState.players.at(gameState.turn).getAbility() == "re-roll"){
                    ReRoll reRoll = ReRoll(this->gameState);
                    reRoll.DoAction();
                }
                else{
                    commandException err(" ", "re-roll");
                    throw err;
                }
                break;
            case 4:
                if(gameState.players.at(gameState.turn).getAbility() == "quadruple"){
                    Quadruple quadruple = Quadruple(this->gameState);
                    quadruple.DoAction();
                }
                else{
                    commandException err(" ", "quadruple");
                    throw err;
                }
                break;
            case 5:
                if(gameState.players.at(gameState.turn).getAbility() == "quarter"){
                    Quarter quarter = Quarter(this->gameState);
                    quarter.DoAction();
                }
                else{
                    commandException err(" ", "quarter");
                    throw err;
                }
                break;
            case 6:
                if(gameState.players.at(gameState.turn).getAbility() == "reverseDirection"){
                    ReverseDirection reverseDirection = ReverseDirection(this->gameState);
                }
                else{
                    commandException err(" ", "reverseDirection");
                    throw err;
                }
                break;
            case 7:
                if(gameState.players.at(gameState.turn).getAbility() == "swap-card"){
                    int noPlayer1, noPlayer2, noKartu1, noKartu2;
                    cout << "Masukkan nomor urut pemain pertama yang ingin ditukar" << endl;
                    cin >> noPlayer1;
                    cout << "Masukkan nomor urut pemain kedua yang ingin ditukar" << endl;
                    cin >> noPlayer2;
                    cout << "Pilih kiri atau kanan dari pemain pertama" << endl;
                    cin >> noKartu1;
                    cout << "Pilih kiri atau kanan dari pemain kedua" << endl;
                    cin >> noKartu2;
                    SwapCard swapCard = SwapCard(this->gameState, noPlayer1, noPlayer2, noKartu1, noKartu2);
                    swapCard.DoAction();
                }
                else{
                    commandException err(" ", "swap-card");
                    throw err;
                }
                break;
            case 8:
                if(gameState.players.at(gameState.turn).getAbility() == "switch"){
                    int noPlayer;
                    cout << "Masukkan no pemain yang akan ditukar dengan Anda" << endl;
                    cin >> noPlayer;
                    Switch swit = Switch(this->gameState, noPlayer);
                    swit.DoAction();
                }
                else{
                    commandException err(" ", "switch");
                    throw err;
                }
                break;
            case 9:
                if(gameState.players.at(gameState.turn).getAbility() == "abilityLess"){
                    AbililyLess abillityLess = AbilityLess(this->gameState);
                    abilityLess.DoAction(); 
                }
                else{
                    commandException err(" ", "abillityLess");
                    throw err;
                }
                break;

            default:
                break;
            }
        }
        
};

#endif