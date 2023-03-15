#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <vector>
#include "../player/player.hpp"
#include "../card/deckCard.hpp"
#include "../card/tableCard.hpp"

class GameState {
    public:
        vector<Player> players;
        DeckCard deckCard;
        TableCard tableCard;
        long long int point;
        vector<int> order;
        int turn;

        GameState(){
            this->players = {Player(), Player(), Player(), Player(), Player(), Player(), Player()};
            this->deckCard = DeckCard();
            this->tableCard = TableCard();
            this->point = 64;
            this->order = {0,1,2,3,4,5,6};
            this->turn = 0;
        }

        GameState(long long int point, vector<int> order, int turn, bool canUseAbility, vector<Player> players, DeckCard deckCard, TableCard tableCard){
            this->players = players;
            this->deckCard = deckCard;
            this->tableCard = tableCard;
            this->point = point;
            this->order = order;
            this->turn = turn;
        }

        GameState(const GameState& other){
            this->players = other.players;
            this->deckCard = other.deckCard;
            this->tableCard = other.tableCard;
            this->point = other.point;
            this->order = other.order;
            this->turn = other.turn;
        }

        GameState& operator=(const GameState& other){
            if(this != &other){
                this->players = other.players;
                this->deckCard = other.deckCard;
                this->tableCard = other.tableCard;
                this->point = other.point;
                this->order = other.order;
                this->turn = other.turn;
            }
            return *this;
        }

        void printState(){
            cout << "DeckCard" << endl;
            int lDC = deckCard.getCard().size();
            cout << "ukuran deckCard " << lDC << endl;

            cout << "Players" << endl;
            int lP = players.size();
            for(int i=0;i<lP;i++){
                cout << "Player name:" << players.at(i).getName() << endl;
                vector<Card> pC = players.at(i).getPlayerCard().getCard();
                int lPC = pC.size();
                cout << lPC << endl;
                for(int j=0;j<lPC;j++){
                    cout << pC.at(j).getColor() << " " << pC.at(j).getNumber() << endl;
                }
                cout << "ability: " << players.at(i).getAbility() << endl;
            }

            cout << "Table Card" << endl;
            for(int i=0;i<tableCard.getCardListLength();i++){
                cout << tableCard.getCard().at(i) << endl;
            }

            cout << "Poin = " << point << endl;

            cout << "Urutan" << endl;
            for(int i=0;i<7;i++){
                cout << order.at(i) << " ";
            }
            cout << endl;

            cout << "Giliran siapa" << endl;
            cout << turn << endl;
        }
};

#endif