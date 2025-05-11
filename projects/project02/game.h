#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    static const int GRID_SIZE = 5;
    static const int NUM_SHIPS = 5;
    static const int EMPTY = 0;
    static const int SHIP = 1;
    static const int X = 2;
    static const int O = 3;

    static const int PLAYER_1 = 1;
    static const int PLAYER_2 = 2;
    static const int PLAYER_1_WINS = 3;
    static const int PLAYER_2_WINS = 4;
    static const int ONGOING = 5;

    Game();

    void switchTurn();
    bool isGameOver();
    std::string play(int row, int col);
    int getCurrentPlayer();
    int status();
    void printGrid(int grid[5][5], bool hideShips);
    int (*getPlayer1Grid())[5];  
    int (*getPlayer2Grid())[5]; 

private:
    int player1Grid[5][5];
    int player2Grid[5][5];
    int player1ShipsRemaining;
    int player2ShipsRemaining;
    int currentPlayer;
    int currentStatus;

    bool validCoord(int row, int col) const;
};

#endif
