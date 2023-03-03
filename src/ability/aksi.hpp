#ifndef AKSI_HPP
#define AKSI_HPP

#include <iostream>
#include "action.hpp"

using namespace std;

class Aksi : public Action {
public:
    Aksi() {}
    Aksi (GameState gameState) : Action(gameState) {}
    void DoAction() {
        cout << "Objek ini untuk mengonstruk" << endl;
    }
};

#endif