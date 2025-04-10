#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <array>

class Game {
public:
    enum Status { ONGOING, PLAYER_X_WINS, PLAYER_O_WINS, DRAW };
    enum Cell { EMPTY, X, O };

    Game();

    void play(int row, int col);
    Status status() const;

    friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
    std::array<std::array<Cell, 3>, 3> board;
    bool xTurn;
    Status currentStatus;

    bool isWinningMove(Cell player) const;
    bool isDraw() const;
};

#endif
