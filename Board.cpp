#include "Board.hpp"

Board::Board() {
    // Initialize the board
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void Board::display() {
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << board[i][j] << " ";
            if (j < 2)
                std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2)
            std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

bool Board::placeMark(int cell, char mark) {
    if (cell < 1 || cell > 9)
        return false;

    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (board[row][col] == ' ') {
        board[row][col] = mark;
        return true;
    } else {
        return false;
    }
}

char Board::checkWinner() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];
    }

    for (int i = 0; i < 3; ++i) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i];
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2];

    return ' ';
}

bool Board::isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool Board::isCellEmpty(int cell){
    if (cell < 1 || cell > 9)
        return false;

    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    return (board[row][col] == ' ');
}

void Board::clearBoard()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}