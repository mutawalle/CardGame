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
        bool canUseAbility;

        GameState(){
            this->players = {Player(), Player(), Player(), Player(), Player(), Player(), Player()};
            this->deckCard = DeckCard();
            this->tableCard = TableCard();
            this->point = 64;
            this->order = {0,1,2,3,4,5,6};
            this->turn = 0;
            this->canUseAbility = false;
        }

        GameState(long long int point, vector<int> order, int turn, bool canUseAbility, vector<Player> players, DeckCard deckCard, TableCard tableCard){
            this->players = players;
            this->deckCard = deckCard;
            this->tableCard = tableCard;
            this->point = point;
            this->order = order;
            this->turn = turn;
            this->canUseAbility = canUseAbility;
        }

        GameState(const GameState& other){
            this->players = other.players;
            this->deckCard = other.deckCard;
            this->tableCard = other.tableCard;
            this->point = other.point;
            this->order = other.order;
            this->turn = other.turn;
            this->canUseAbility = other.canUseAbility;
        }

        GameState& operator=(const GameState& other){
            if(this != &other){
                this->players = other.players;
                this->deckCard = other.deckCard;
                this->tableCard = other.tableCard;
                this->point = other.point;
                this->order = other.order;
                this->turn = other.turn;
                this->canUseAbility = other.canUseAbility;
            }
            return *this;
        }

        void printState(){
            cout << "DeckCard" << endl;
            int lDC = deckCard.getCard().size();
            for(int i=0;i<lDC;i++){
                cout << deckCard.getCard().at(i).getColor() << " " << deckCard.getCard().at(i).getNumber() << endl;
            }

            cout << "Players" << endl;
            int lP = players.size();
            for(int i=0;i<lP;i++){
                cout << "Player ke-" << i+1 << endl;
                vector<Card> pC = players.at(i).getPlayerCard().getCard();
                int lPC = pC.size();
                for(int j;j<lPC;j++){
                    cout << pC.at(j).getColor() << " " << pC.at(j).getColor() << endl;
                }
            }

            cout << "Table Card" << endl;
            int lTC = tableCard.getCard().size();
            for(int i=0;i<lTC;i++){
                cout << tableCard.getCard().at(i).getColor() << " " << tableCard.getCard().at(i).getColor() << endl;
            }

            cout << "Poin = " << point << endl;

            cout << "Urutan" << endl;
            for(int i=0;i<7;i++){
                cout << order.at(i) << " ";
            }

            cout << "Giliran siapa" << endl;
            cout << turn << endl;

            cout << "Bisa ability?" << endl;
            canUseAbility ? cout << "Bisa" << endl : cout << "Tidak" << endl;
        }
};

#endif