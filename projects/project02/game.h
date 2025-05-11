#ifndef GAME_H
#define GAME_H

#include <iostream>

const int GRID_SIZE = 5;

enum CellState { EMPTY, SHIP, HIT, MISS };
enum GameStatus { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS };
enum Player { PLAYER_1, PLAYER_2 };

class Game {
private:
    CellState player1Grid[GRID_SIZE][GRID_SIZE];
    CellState player2Grid[GRID_SIZE][GRID_SIZE];
    Player currentPlayer;
    GameStatus gameStatus;
    int player1ShipsRemaining;
    int player2ShipsRemaining;

    void switchTurn();
    bool validCoord(int row, int col) const;
    void printGrid(const CellState grid[GRID_SIZE][GRID_SIZE], bool hideShips) const;

public:
    Game();
    void play(int row, int col);
    GameStatus status() const;
    Player getCurrentPlayer() const;

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif
