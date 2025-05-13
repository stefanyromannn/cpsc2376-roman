#ifndef GAME_H
#define GAME_H

#include <string>
#include <SDL2/SDL.h>

class Game {
public:
    static const int GRID_SIZE = 5;
    static const int EMPTY = 0;
    static const int SHIP = 1;
    static const int HIT = 2;
    static const int MISS = 3;

    Game();

    void switchTurn();
    bool isGameOver() const;
    std::string play(int row, int col);
    int getCurrentPlayer() const;
    void renderGrid(int grid[GRID_SIZE][GRID_SIZE], bool hideShips, SDL_Renderer* renderer) const;

    int (*getPlayer1Grid())[GRID_SIZE];
    int (*getPlayer2Grid())[GRID_SIZE];

private:
    int player1Grid[GRID_SIZE][GRID_SIZE];
    int player2Grid[GRID_SIZE][GRID_SIZE];
    int player1ShipsRemaining;
    int player2ShipsRemaining;
    int currentPlayer;

    bool validCoord(int row, int col) const;
    void placeShipsRandomly(int grid[GRID_SIZE][GRID_SIZE]);
};

#endif 
