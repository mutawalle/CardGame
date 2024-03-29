#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <bits/stdc++.h>
#include <unistd.h>
#include <cstdlib>
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
map<string, string> colorsCodeCommand = {{"HIJAU", "\033[32m"}, {"BIRU", "\033[34m"}, {"KUNING", "\033[33m"}, {"MERAH", "\033[31m"}, {"MAGENTA", "\033[35m"}, {"CYAN", "\033[36m"}, {"RESET", "\033[0m"}};

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
            char curDir[256];
            vector<Card> vectorCard = {};
            DeckCard deckCard(vectorCard);
            string myText;

            getcwd(curDir, sizeof(curDir));

            cout << "Masukkan nama file(pastikan berada di folder input): ";
            cin >> namaFile;
            
            this->gameState.deckCard = deckCard;
            ifstream MyReadFile(string(curDir)+"/src/input/"+namaFile+".txt");
            if(!MyReadFile){
                fileException err(false);
                throw err;
            }

            for(int i=0;i<52;i++){
                vector<string> words = {};
                string word;
                getline (MyReadFile, myText);
                stringstream ss(myText);

                while(ss >> word){
                    words.push_back(word);
                }

                if(words.size() != 2 || distance(colors.begin(), find(colors.begin(), colors.end(), words.at(0)))<0 || distance(colors.begin(), find(colors.begin(), colors.end(), words.at(0)))>3 || stoi(words.at(1))<0 || stoi(words.at(1))>13){
                    fileException err(true);
                    throw err;
                }else{
                    Card tmp(stoi(words.at(1)), words.at(0));

                    vector<Card> deckCards = this->gameState.deckCard.getCard();
                    deckCards.push_back(tmp);
                    this->gameState.deckCard = deckCards;
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
                
                if(words.size() != 1 || distance(abilities.begin(), find(abilities.begin(), abilities.end(), words.at(0)))<0 || distance(abilities.begin(), find(abilities.begin(), abilities.end(), words.at(0)))>6){
                    fileException err(true);
                    throw err;
                }else{
                    this->gameState.players.at(i).setAbility(words.at(0));
                    myText = "";
                }
            }

            MyReadFile.close();
        }

        void chooseSplitingCard(){
            int tmp;
            do {
                cout << "Silakan memilih metode pembagian kartu: " << endl;
                cout << "1. Random" << endl;
                cout << "2. File" << endl;
                cout << "Masukan pilihan: ";
                cin >> tmp;
                if(tmp == 2){
                    bool valid = false;
                    while(!valid){
                        try{
                            inputFile();
                            valid = true;
                        }
                        catch(fileException err){
                            err.errMessage();
                        }
                    }
                }
            }while(tmp<1 || tmp>2);
            system("clear");
            system("cls");
        }

        void inputName(){
            cout << "Silakan isi nama setiap pemain" << endl;
            for(int i=0;i<7;i++){
                string name;
                cout << "Masukan nama pemain ke-" << i+1 << " : ";
                cin >> name;
                this->gameState.players.at(i).setName(name);
            }
            system("cls");
            system("clear");
        }

        void splashRound(int n){
            vector<int> order = this->gameState.order;
            cout << colorsCodeCommand["CYAN"] << "RONDE " << n << colorsCodeCommand["RESET"] << endl;
            cout << "Sekarang giliran " << this->gameState.players.at(order.at(this->gameState.turn)).getName() << endl;
            cout << "Ini kartu kamu" << endl;
            cout << this->gameState.players.at(order.at(this->gameState.turn)).getPlayerCard();
            cout << "Ini kartu di meja" << endl;
            cout << this->gameState.tableCard;
            cout << "poin kamu: " << this->gameState.players.at(order.at(this->gameState.turn)).getPoint() << endl;
            cout << "poin game: " << this->gameState.point << endl;
            if(n >= 2){
                cout << "ability kamu: " << this->gameState.players.at(order.at(this->gameState.turn)).getAbility() << endl;
            }
        }

        void commandValidation(){
            cout<<"silakan input command : ";
            cin >> command;
            cout << endl;
            auto In = commands.find(command);
            if(In == commands.end()){
                commandException err(command, " ", gameState);
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
                    string s;
                    cout << "Ketik apapun untuk lanjut ke pemain berikutnya: ";
                    cin >> s;
                    system("cls");
                    system("clear");
                }
                catch(commandException err){
                    system("clear");
                    system("cls");
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
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "RE-ROLL" && gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess() == false){
                    gameState.players.at(gameState.order.at(gameState.turn)).setAbility("");
                    ReRoll reRoll(this->gameState);
                    reRoll.DoAction();
                    this->gameState = reRoll.GetGameState();
                }
                else{
                    commandException err(" ", "RE-ROLL", gameState);
                    throw err;
                }
                break;
            }
            case 4:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "QUADRUPLE" && gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess() == false){
                    gameState.players.at(gameState.order.at(gameState.turn)).setAbility("");
                    Quadruple quadruple(this->gameState);
                    quadruple.DoAction();
                    this->gameState = quadruple.GetGameState();
                }
                else{
                    commandException err(" ", "QUADRUPLE", gameState);
                    throw err;
                }
                break;
            }
            case 5:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "QUARTER" && gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess() == false){
                    gameState.players.at(gameState.order.at(gameState.turn)).setAbility("");
                    Quarter quarter(this->gameState);
                    quarter.DoAction();
                    this->gameState = quarter.GetGameState();
                }
                else{
                    commandException err(" ", "QUARTER", gameState);
                    throw err;
                }
                break;
            }
            case 6:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "REVERSE" && gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess() == false){
                    gameState.players.at(gameState.order.at(gameState.turn)).setAbility("");
                    ReverseDirection reverseDirection(this->gameState);
                    reverseDirection.DoAction();
                    this->gameState = reverseDirection.GetGameState();
                }
                else{
                    commandException err(" ", "REVERSE", gameState);
                    throw err;
                }
                break;
            }
            case 7:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "SWAP" && gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess() == false){
                    gameState.players.at(gameState.order.at(gameState.turn)).setAbility("");
                    vector<Player> listTarget;
                    for(size_t i = 0; i<gameState.players.size(); i++){
                        if(i != order.at(this->gameState.turn)){
                            listTarget.push_back(gameState.players[i]);
                        }
                    }
                    for(size_t i = 0; i<listTarget.size(); i++){
                        cout << i+1<< ". "<<listTarget[i].getName()<<endl;
                    }
                    cout << gameState.players.at(order.at(this->gameState.turn)).getName() << " akan melakukan swap"<< endl;
                    int noPlayer1, noPlayer2, noKartu1, noKartu2;
                    cout << "Masukkan nomor urut pemain pertama yang ingin ditukar" << endl;
                    cin >> noPlayer1;
                    while(noPlayer1 < 1 || noPlayer1 >6){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> noPlayer1;
                    }
                    int index1;
                    for (int i = 0; i<gameState.players.size(); i++){
                        if(gameState.players[i].getPlayerCard().getCard().at(0) == listTarget[noPlayer1-1].getPlayerCard().getCard().at(0)){
                            index1 = i;
                        }
                    }
                    listTarget.erase(listTarget.begin() + noPlayer1-1);
                    for(size_t i = 0; i<listTarget.size(); i++){
                        cout << i+1<< ". "<<listTarget[i].getName()<<endl;
                    }
                    cout << "Masukkan nomor urut pemain kedua yang ingin ditukar" << endl;
                    cin >> noPlayer2;
                    while(noPlayer2 < 1 || noPlayer2 >5){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> noPlayer2;
                    }
                    int index2;
                    for (int i = 0; i<gameState.players.size(); i++){
                        if(gameState.players[i].getPlayerCard().getCard().at(0) == listTarget[noPlayer2-1].getPlayerCard().getCard().at(0)){
                            index2 = i;
                        }
                    }
                    cout << "Pilih kiri atau kanan dari pemain pertama" << endl;
                    cout << "1. Kiri"<<endl;
                    cout << "2. Kanan"<< endl;
                    cin >> noKartu1;
                    while(noKartu1 <1 || noKartu1 > 2){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> noKartu1;
                    }
                    cout << "Pilih kiri atau kanan dari pemain kedua" << endl;
                    cout << "1. Kiri"<<endl;
                    cout << "2. Kanan"<< endl;
                    cin >> noKartu2;
                    while(noKartu2 <1 || noKartu2 > 2){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> noKartu2;
                    }
                    SwapCard swapCard(this->gameState, index1, index2, noKartu1-1, noKartu2-1);
                    swapCard.DoAction();
                    this->gameState = swapCard.GetGameState();
                }
                else{
                    commandException err(" ", "SWAP", gameState);
                    throw err;
                }
                break;
            }
            case 8:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "SWITCH" && gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess() == false){
                    gameState.players.at(gameState.order.at(gameState.turn)).setAbility("");
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
                        cout << i+1<< ". "<<listTarget[i].getName()<<endl;
                    }
                    cin >> noPlayer;
                    while(noPlayer < 1 || noPlayer >6){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> noPlayer;
                    }
                    int index;
                    for (int i = 0; i<gameState.players.size(); i++){
                        if(gameState.players[i].getPlayerCard().getCard().at(0) == listTarget[noPlayer-1].getPlayerCard().getCard().at(0)){
                            index = i;
                        }
                    }
                    Switch swit = Switch(this->gameState, index);
                    swit.DoAction();
                    this->gameState = swit.GetGameState();
                }
                else{
                    commandException err(" ", "SWITCH", gameState);
                    throw err;
                }
                break;
            }
            case 9:
            {
                if(gameState.players.at(order.at(this->gameState.turn)).getAbility() == "ABILITYLESS" && gameState.players.at(order.at(this->gameState.turn)).getIsAbilityLess() == false){
                    gameState.players.at(gameState.order.at(gameState.turn)).setAbility("");
                    vector<Player> listTarget;
                    cout << gameState.players.at(order.at(this->gameState.turn)).getName() << " akan mematikan kartu ablity lawan!"<< endl;
                    cout << "silahkan pilih nomor pemain yang ingin dimatikan!"<< endl;
                    for(size_t i = 0; i<gameState.players.size(); i++){
                        if(i != order.at(this->gameState.turn)){
                            listTarget.push_back(gameState.players[i]);
                        }
                    }
                    for(size_t i = 0; i<listTarget.size(); i++){
                        cout << i+1<< ". "<<listTarget[i].getName()<<endl;
                    }
                    int nomorTarget;
                    cin >> nomorTarget;
                    while(nomorTarget < 1 || nomorTarget >6){
                        cout << "input tidak valid!! ulangi "<<endl;
                        cin >> nomorTarget;
                    }
                    int index;
                    for (int i = 0; i<gameState.players.size(); i++){
                        if(gameState.players[i].getPlayerCard().getCard().at(0) == listTarget[nomorTarget-1].getPlayerCard().getCard().at(0)){
                            index = i;
                        }
                    }

                    AbilityLess abilityLess = AbilityLess(this->gameState, index);
                    abilityLess.DoAction(); 
                    this->gameState = abilityLess.GetGameState();
                }
                else{
                    commandException err(" ", "ABILITYLESS", gameState);
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