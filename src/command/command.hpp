#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <bits/stdc++.h> 
#include "../game/gameState.hpp" 
#include "commandException.hpp"
#include "../ability/action.hpp"

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
            Action action(gameState);
            switch (listCommand[command])
            {
            case 0:
                action.Next();
                break;
            case 1:
                action.half();
                break;
            case 2:
                action.Double();
                break;
            case 3:
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "re-roll"){
                    action.reRoll();
                }
                else{
                    commandException err(" ", "re-roll");
                    throw err;
                }
                break;
            case 4:
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "quadruple"){
                    action.Quadruple();
                }
                else{
                    commandException err(" ", "quadruple");
                    throw err;
                }
                break;
            case 5:
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "qurter"){
                    action.Quarter();
                }
                else{
                    commandException err(" ", "quarter");
                    throw err;
                }
                break;
            case 6:
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "reverseDirection"){
                    action.reverseDirection();
                }
                else{
                    commandException err(" ", "reverseDirection");
                    throw err;
                }
                break;
            case 7:
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "swap-card"){
                    action.swapCard();
                }
                else{
                    commandException err(" ", "swap-card");
                    throw err;
                }
                break;
            case 8:
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "switch"){
                    action.switch();
                }
                else{
                    commandException err(" ", "switch");
                    throw err;
                }
                break;
            case 9:
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "abilityLess"){
                    action.abillityLess();
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