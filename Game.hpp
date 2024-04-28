#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Player.hpp"

class Game {
public:
    Game();
    //void start();
    void mainMenu();
    void exitMenu();

private:
    Board board;
    Player player1;
    Player player2;
    char currentPlayerMark;
    bool gameOver;
    int gameType; //true = HumanvHUman, false = HumanvComputer

    
    void humanVhuman();
    void humanVcomputer();
    int getRandomMove();
    void switchPlayer();
};

#endif 