#include "Game.hpp"
#include <cstdlib> // For rand and srand
#include <ctime>   // For time

Game::Game() : player1('X'), player2('O'), currentPlayerMark('X'), gameOver(false) {}

void Game::mainMenu(){
    int input;
    std::cout << "\nMenu\n(1) human vs human\n(2) human vs computer\n";
    std::cin >> input;
   while(input != 1 && input != 2){
        std::cout << "\ninvalid entry!";
        std::cout << "\nMenu\n(1) human vs human\n(2) human vs computer\n";
        std::cin >> input;
    }

    if(input == 1){
        humanVhuman();
    }
    if(input == 2){
        humanVcomputer();
    }
}

void Game::humanVhuman(){
    gameType = 1;
    while (!gameOver) {
        board.display();
        int cell = (currentPlayerMark == 'X') ? player1.makeMove() : player2.makeMove();
        if (board.placeMark(cell, currentPlayerMark)) {
            char winner = board.checkWinner();
            if (winner != ' ') {
                board.display();
                if (winner == 'X')
                    std::cout << "Player one wins!\n";
                else
                    std::cout << "Player two wins!\n";
                exitMenu();
            } else if (board.isBoardFull()) {
                board.display();
                std::cout << "It's a draw!\n"; //draw isnt working???
                exitMenu();
            } else {
                switchPlayer();
            }
        } else {
            std::cout << "That move is invalid!\n";
        }
    }
}

void Game::humanVcomputer() {
     gameType = -1;
    while (!gameOver) {
        board.display();
        if (currentPlayerMark == 'X') {
            int cell;
            std::cout << "Your move: ";
            std::cin >> cell;
            if (board.placeMark(cell, currentPlayerMark)) {
                char winner = board.checkWinner();
                if (winner != ' ') {
                    board.display();
                    if (winner == 'X')
                        std::cout << "You win!\n";
                    else
                        std::cout << "Computer wins!\n";
                    exitMenu(); //
                } else if (board.isBoardFull()) {
                    board.display();
                    std::cout << "It's a draw!\n";
                    exitMenu();//
                } else {
                    switchPlayer();
                }
            } else {
                std::cout << "That move is invalid!\n";
            }
        } else {
            std::cout << "Computer's move: ";
            int cell = getRandomMove();
            std::cout << cell << std::endl;
            if (board.placeMark(cell, currentPlayerMark)) {
                char winner = board.checkWinner();
                if (winner != ' ') {
                    board.display();
                    if (winner == 'X')
                        std::cout << "You win!\n";
                    else
                        std::cout << "Computer wins!\n";
                    exitMenu();
                } else if (board.isBoardFull()) {
                    board.display();
                    std::cout << "It's a draw!\n";
                    exitMenu();
                } else {
                    switchPlayer();
                }
            }
        }
    }
}

int Game::getRandomMove() {
    srand(time(0)); // Seed 
    int move;
    do {
        move = rand() % 9 + 1; // Generate a rand num 1-9
    } while (!board.isCellEmpty(move)); // generate until empty cell is found
    return move;
}

void Game::exitMenu(){
    int input;
    //would the player want to play again?
    std::cout << "\nWould you like to play the same game again?\n(1)Yes\n(2)No\n";
    std::cin >> input;

    if(input == 1)
    {
        board.clearBoard();
        gameOver = false;
        if(gameType == 1)
        {
            humanVhuman();
        }
        else if(gameType == -1)
        {
            humanVcomputer();
        }
    }

    else{
        gameOver = true;
        std::cout << "\nGame Over \n\nGoodbye!";
    }
    
}


void Game::switchPlayer() {
    currentPlayerMark = (currentPlayerMark == 'X') ? 'O' : 'X';
}