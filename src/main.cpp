#include <iostream>
#include <cstdlib>
#include "bonus/GameBj.hpp"
#include "game/game.hpp"

using namespace std;

void opening();

int main(){
    string n;
    opening();
    cout << "Pilih Game:" << endl;
    cout << "1. Candy Card" << endl;
    cout << "2. Black Jack" << endl; 
    cout << "Ketik lainnya untuk exit" << endl;
    cin >> n;
    system("clear");
    system("cls");
    if(n=="1"){
        Game game;
        game.start();
    }else if(n=="2"){
        GameBJ game;
        game.startGame();
    }else{
        cout << "BYE" << endl;
    }
}

void opening(){
    cout << "\033[35m" << R"(
     _.-(_)._     ."          ".      .--""--.          _.-{__}-._
   .'________'.   | .--------. |    .'        '.      .:-'`____`'-:.
  [____________] /` |________| `\  /   .'``'.   \    /_.-"`_  _`"-._\
  /  / .\/. \  \|  / / .\/. \ \  ||  .'/.\/.\'.  |  /`   / .\/. \   `\
  |  \__/\__/  |\_/  \__/\__/  \_/|  : |_/\_| ;  |  |    \__/\__/    |
  \            /  \            /   \ '.\    /.' / .-\                /-.
  /'._  --  _.'\  /'._  --  _.'\   /'. `'--'` .'\/   '._-.__--__.-_.'   \
 /_   `""""`   _\/_   `""""`   _\ /_  `-./\.-'  _\'.    `""""""""`    .'`\
(__/    '|    \ _)_|           |_)_/            \__)|        '       |   |
  |_____'|_____|   \__________/   |              | `_________'________`;-'
   '----------'    '----------'   '--------------'`--------------------`
          \ \    / /| __|| |   | |          / __|| | | ||  \/  |
           \ \/\/ / | _| | |__ | |__       | (__ | |_| || |\/| |
            \_/\_/  |___||____||____|       \___| \___/ |_|  |_|
)" << "\033[0m" <<endl;
}