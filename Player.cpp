#include "Player.hpp"
#include <iostream>

Player::Player(char mark) : mark(mark) {}

int Player::makeMove() {
    int cell;
    std::cout << "Player " << mark << " - where would you like to move? ";
    std::cin >> cell;
    return cell;
}
