#ifndef GAME_H
#define GAME_H

class Game {
    private:
        // gameState
        // ronde keberapa (int)
        // urutan (list of int)
        // isFinish (boolean) untuk menandakan apakah sudah ada pemenangnya
        // tableCard (list of card)
    public:
        void start();
        void splitCards();
        void ronde();
};

#endif