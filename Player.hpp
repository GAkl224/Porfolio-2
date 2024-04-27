#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
public:
    Player(char mark);
    int makeMove();

private:
    char mark;
};

#endif // PLAYER_HPP