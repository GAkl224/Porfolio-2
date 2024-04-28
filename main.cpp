#include "Game.hpp"

int main() {
    Game game;
    game.mainMenu();
    return 0;
}

//to compile: g++ -o tictactoe main.cpp Game.cpp Player.cpp Board.cpp