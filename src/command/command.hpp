#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <bits/stdc++.h>
#include "../game/gameState.hpp"
#include "commandException.hpp"
#include "../ability/Action.hpp"

using namespace std;
vector<string> listCommand = {"re-roll", "quadruple", "quarter", "reverse", "swap", "switch", "abilityless", "next", "double", "half"};
class Command {
    private:
        GameState gameState;
        string command;
    public: 
        // Command(GameState gameState){
        //     this->gameState = gameState;
        // }

        void commandValidation(){
            cout<<"silahkan input command : ";
            cin >> command;
            cout << endl;
            bool isIn = false;
            for(int i = 0; i < listCommand.size(); i++){
                if(command == listCommand[i]){
                    isIn = true;
                    break;
                }
            }
            if(!isIn){
                commandException err(command, " ");
                throw err;

            }
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
            switch (command)
            {
            case "next":
                action.Next();
                break;
            case "half":
                action.half();
                break;
            case "double":
                action.Double();
                break;
            case "re-roll":
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "re-roll"){
                    action.reRoll();
                }
                else{
                    commandException err(" ", "re-roll");
                    throw err;
                }
                break;
            case "quadruple":
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "quadruple"){
                    action.Quadruple();
                }
                else{
                    commandException err(" ", "quadruple");
                    throw err;
                }
                break;
            case "quater":
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "qurter"){
                    action.Quarter();
                }
                else{
                    commandException err(" ", "quarter");
                    throw err;
                }
                break;
            case "reverseDirection":
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "reverseDirection"){
                    action.reverseDirection();
                }
                else{
                    commandException err(" ", "reverseDirection");
                    throw err;
                }
                break;
            case "swap-card":
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "swap-card"){
                    action.swapCard();
                }
                else{
                    commandException err(" ", "swap-card");
                    throw err;
                }
                break;
            case "switch":
                if(gameState.getPlayer(gameState.getTurn()).getAbillity() == "switch"){
                    action.switch();
                }
                else{
                    commandException err(" ", "switch");
                    throw err;
                }
                break;
            case "abillityless":
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