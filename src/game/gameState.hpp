#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <vector>
#include "../player/player.hpp"
#include "../card/deckCard.hpp"
#include "../card/tableCard.hpp"

class GameState {
    private:
        vector<Player> players;
        DeckCard deckCard;
        TableCard tableCard;
        long long int point;
        vector<int> order;
        int turn;
        bool canUseAbility;
    public:
        GameState(){
            players = {Player(), Player(), Player(), Player(), Player(), Player(), Player()};
            this->point = 64;
            this->order = {0,1,2,3,4,5,6};
            this->turn = 0;
            this->canUseAbility = false;
        }

        GameState(long long int point, vector<int> order, int turn, bool canUseAbility){
            this->point = point;
            this->order = order;
            this->turn = turn;
            this->canUseAbility = canUseAbility;
        }

        GameState& operator=(const GameState& other){
            if(this != &other){
                this->point = other.point;
                this->order = other.order;
                this->turn = other.turn;
                this->canUseAbility = other.canUseAbility;
            }
            return *this;
        }

        setPlayers(vector<Player>){
            return this->
        }
};

#endif