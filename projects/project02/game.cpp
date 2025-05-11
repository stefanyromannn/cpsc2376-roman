#include "game.h"
#include <cstdlib>

Game::Game() {
    // Initialize board
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            player1Grid[i][j] = EMPTY;
            player2Grid[i][j] = EMPTY;
        }
    }

    // Place 3 ships manually (for simplicity)
    player1Grid[0][0] = SHIP;
    player1Grid[1][1] = SHIP;
    player1Grid[2][2] = SHIP;

    player2Grid[0][2] = SHIP;
    player2Grid[1][3] = SHIP;
    player2Grid[2][4] = SHIP;

    player1ShipsRemaining = 3;
    player2ShipsRemaining = 3;
    currentPlayer = PLAYER_1;
    gameStatus = ONGOING;
}

void Game::switchTurn() {
    currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
}

bool Game::validCoord(int row, int col) const {
    return row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE;
}

void Game::play(int row, int col) {
    if (!validCoord(row, col) || gameStatus != ONGOING) return;

    CellState (*opponentGrid)[GRID_SIZE] = (currentPlayer == PLAYER_1) ? player2Grid : player1Grid;
    int& opponentShips = (currentPlayer == PLAYER_1) ? player2ShipsRemaining : player1ShipsRemaining;

    if (opponentGrid[row][col] == SHIP) {
        opponentGrid[row][col] = HIT;
        opponentShips--;
    } else if (opponentGrid[row][col] == EMPTY) {
        opponentGrid[row][col] = MISS;
    } else {
        // Already hit/miss — ignore
        return;
    }

    if (opponentShips == 0) {
        gameStatus = (currentPlayer == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
    } else {
        switchTurn();
    }
}

GameStatus Game::status() const {
    return gameStatus;
}

Player Game::getCurrentPlayer() const {
    return currentPlayer;
}

void Game::printGrid(const CellState grid[GRID_SIZE][GRID_SIZE], bool hideShips) const {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            switch (grid[i][j]) {
                case EMPTY: std::cout << "."; break;
                case SHIP: std::cout << (hideShips ? "." : "S"); break;
                case HIT: std::cout << "X"; break;
                case MISS: std::cout << "O"; break;
            }
        }
        std::cout << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "\nYour turn: Player " << (game.currentPlayer == PLAYER_1 ? "1" : "2") << "\n";
    os << "Opponent's board:\n";

    if (game.currentPlayer == PLAYER_1)
        game.printGrid(game.player2Grid, true);
    else
        game.printGrid(game.player1Grid, true);

    return os;
}
