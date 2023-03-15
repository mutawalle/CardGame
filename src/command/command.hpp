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

map<string, int> commands = {{"NEXT", 0}, {"DOUBLE", 1}, {"HALF", 2}, {"RE-ROLL", 3}, {"QUADRUPLE", 4}, {"QUARTER", 5}, {"REVERSE", 6}, {"SWAP",7}, {"SWITCH", 8}, {"ABILITYLESS", 9}};

class Command {
    private:
        GameState gameState;
        string command;
    public: 
        Command(GameState gameState){
            this->gameState = gameState;
        }

        GameState getGamestate(){
            return gameState;
        }

        void setGameState(GameState gameState){
            this->gameState = gameState;
        }

        void inputFile(){
            vector<string> colors = {"HIJAU", "MERAH", "KUNING", "BIRU"};
            vector<string> abilities = {"RE-ROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP","SWITCH", "ABILITYLESS"};
            string namaFile;
            cin >> namaFile;
            string myText;

            ifstream MyReadFile(namaFile+".txt");

            for(int i=0;i<52;i++){
                vector<string> words = {};
                string word;
                getline (MyReadFile, myText);
                stringstream ss(myText);

                while(ss >> word){
                    words.push_back(word);
                }

                if(words.size() != 2 || find(colors.begin(), colors.end(), words.at(0)) == colors.end() || stoi(words.at(1))>0 && stoi(words.at(1))<14){
                    //exceptionS
                }else{
                    Card tmp(stoi(words.at(1)), words.at(0));
                    this->gameState.deckCard + tmp;
                }
            }
            for(int i=0;i<7;i++){
                vector<string> words = {};
                string word;
                getline (MyReadFile, myText);
                stringstream ss(myText);

                while(ss >> word){
                    words.push_back(word);
                }

                if(words.size() != 1 || find(abilities.begin(), abilities.end(), words.at(0)) == abilities.end()){
                    //exception
                }else{
                    this->gameState.players.at(i).setAbility(words.at(0));
                }
            }

            MyReadFile.close();
        }

        void chooseSplitingCard(){
            int tmp;
            cout << "Silakan memilih metode pembagian kartu: " << endl;
            cout << "1. Random" << endl;
            cout << "2. File" << endl;
            cin >> tmp;
            if(tmp == 2){
                inputFile();
            }
        }

        void inputName(){
            cout << "Silakan isi nama setiap pemain" << endl;
            for(int i=0;i<7;i++){
                string name;
                cout << "Masukan nama pemain ke-" << i+1 << endl;
                cin >> name;
                this->gameState.players.at(i).setName(name);
            }
        }

        void splashRound(int n){
            cout << "Ronde ke-" << n << " dimulai" << endl;
        }

        void commandValidation(){
            vector<int> order = this->gameState.order;
            cout << "Sekaran giliran " << this->gameState.players.at(order.at(this->gameState.turn)).getName() << endl;
            cout<<"silahkan input command : ";
            cin >> command;
            cout << endl;
            auto In = commands.find(command);
            if(In == commands.end()){
                commandException err(command, " ", gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess());
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


        void abillityValidation(){
            vector<int> order = this->gameState.order;
            switch (commands[this->command])
            {
            case 0:
            {
                Next next(this->gameState);
                next.DoAction();
                this->gameState = next.GetGameState();
                break;
            }
            case 1:
            {
                Double dble(this->gameState);
                dble.DoAction();
                this->gameState = dble.GetGameState();
                break;
            }
            case 2:
            {
                Half half(this->gameState);
                half.DoAction();
                this->gameState = half.GetGameState();
                break;
            }
            case 3:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "re-roll"){
                    ReRoll reRoll(this->gameState);
                    reRoll.DoAction();
                    this->gameState = reRoll.GetGameState();
                }
                else{
                    commandException err(" ", "re-roll", gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 4:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "quadruple"){
                    Quadruple quadruple(this->gameState);
                    quadruple.DoAction();
                    this->gameState = quadruple.GetGameState();
                }
                else{
                    commandException err(" ", "quadruple", gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 5:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "quarter"){
                    Quarter quarter(this->gameState);
                    quarter.DoAction();
                    this->gameState = quarter.GetGameState();
                }
                else{
                    commandException err(" ", "quarter", gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 6:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "reverseDirection"){
                    ReverseDirection reverseDirection(this->gameState);
                    reverseDirection.DoAction();
                    this->gameState = reverseDirection.GetGameState();
                }
                else{
                    commandException err(" ", "reverseDirection", gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 7:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "swap-card"){
                    vector<Player> listTarget;
                    for(size_t i = 0; i<gameState.players.size(); i++){
                        if(i != order.at(this->gameState.turn)){
                            listTarget.push_back(gameState.players[i]);
                        }
                    }
                    for(size_t i = 0; i<listTarget.size(); i++){
                        cout << i+1<< listTarget[i].getName()<<endl;
                    }
                    cout << gameState.players.at(order.at(this->gameState.turn)).getName() << " akan melakukan swap"<< endl;
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
                    this->gameState = swapCard.GetGameState();
                }
                else{
                    commandException err(" ", "swap-card", gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 8:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "switch"){
                    int noPlayer;
                    vector<Player> listTarget;
                    cout << gameState.players.at(order.at(this->gameState.turn)).getName() << " akan melakukan switch"<< endl;
                    cout << "Kartu sekarang adalah : "<< endl;
                    cout << gameState.players.at(order.at(this->gameState.turn)).getPlayerCard().getCard()[0].getNumber() << " " <<gameState.players.at(order.at(this->gameState.turn)).getPlayerCard().getCard()[0].getColor() << endl;
                    cout << gameState.players.at(order.at(this->gameState.turn)).getPlayerCard().getCard()[1].getNumber() << " " <<gameState.players.at(order.at(this->gameState.turn)).getPlayerCard().getCard()[1].getColor() << endl;
                    cout << "Masukkan no pemain yang akan ditukar dengan Anda" << endl;
                    for(size_t i = 0; i<gameState.players.size(); i++){
                        if(i != order.at(this->gameState.turn)){
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
                    this->gameState = swit.GetGameState();
                }
                else{
                    commandException err(" ", "switch", gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess());
                    throw err;
                }
                break;
            }
            case 9:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "abilityLess"){
                    vector<Player> listTarget;
                    cout << gameState.players.at(order.at(this->gameState.turn)).getName() << " akan mematikan kartu ablity lawan!"<< endl;
                    cout << "silahkan pilih nomor pemain yang ingin dimatikan!"<< endl;
                    for(size_t i = 0; i<gameState.players.size(); i++){
                        if(i != order.at(this->gameState.turn)){
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
                    this->gameState = abilityLess.GetGameState();
                }
                else{
                    commandException err(" ", "abillityLess", gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess());
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