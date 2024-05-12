#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <iomanip>


class Board {
public:
    Board();
    void display();
    bool placeMark(int cell, char mark);
    char checkWinner();
    bool isBoardFull();
    bool isCellEmpty(int cell);
    void clearBoard();

private:
    char board[4][4];
};

#endif 
