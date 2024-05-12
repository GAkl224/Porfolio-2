#include "Board.hpp"

Board::Board() {
    // Initialize the board
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            board[i][j] = ' ';
        }
    }
}

void Board::display() {
     std::cout << "\n";
    int index = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == ' ') {
                std::cout << std::setw(2) << index;
            } else {
                std::cout << std::setw(2) << board[i][j];
            }
            if (j < 3)
                std::cout << " | ";
            index++;
        }
        std::cout << "\n";
        if (i < 3)
            std::cout << std::string(19, '-') << "\n";
    }
    std::cout << "\n";
    
}

bool Board::placeMark(int cell, char mark) {
    if (cell < 1 || cell > 16)
        return false;

    int row = (cell - 1) / 4;
    int col = (cell - 1) % 4;

    if (board[row][col] == ' ') {
        board[row][col] = mark;
        return true;
    } else {
        return false;
    }
}

char Board::checkWinner() {
    //rows
    for (int i = 0; i < 4; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][0] != ' ')
                return board[i][0];
        }

        // Check columns
        for (int j = 0; j < 4; ++j) {
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[0][j] != ' ')
                return board[0][j];
        }

        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[0][0] != ' ')
            return board[0][0];

        if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0] && board[0][3] != ' ')
            return board[0][3];

        // If no winner yet, return space
        return ' ';
}

bool Board::isBoardFull() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool Board::isCellEmpty(int cell){
    if (cell < 1 || cell > 16)
        return false;

    int row = (cell - 1) / 4;
    int col = (cell - 1) % 4;

    return (board[row][col] == ' ');
}

void Board::clearBoard()
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            board[i][j] = ' ';
        }
    }
}