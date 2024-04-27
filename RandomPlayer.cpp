#include "RandomPlayer.hpp"
#include <cstdlib> // For rand
#include <ctime>   // For seeding rand

RandomPlayer::RandomPlayer() {
    srand(time(NULL)); // Seed random number generator
}

int RandomPlayer::makeRandMove() {
    // Generate random move (1-9)
    return rand() % 9 + 1;
}

