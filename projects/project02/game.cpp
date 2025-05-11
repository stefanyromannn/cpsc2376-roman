#include "game.h"
#include <iostream>

Game::Game() : player1ShipsRemaining(NUM_SHIPS), player2ShipsRemaining(NUM_SHIPS), currentPlayer(PLAYER_1), currentStatus(ONGOING) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            player1Grid[i][j] = EMPTY;
            player2Grid[i][j] = EMPTY;
        }
    }
}

void Game::switchTurn() {
    if (currentPlayer == PLAYER_1) {
        currentPlayer = PLAYER_2;
    } else {
        currentPlayer = PLAYER_1;
    }
}

bool Game::isGameOver() {
    return player1ShipsRemaining == 0 || player2ShipsRemaining == 0;
}

std::string Game::play(int row, int col) {
    if (currentPlayer == PLAYER_1) {
        if (validCoord(row, col) && player2Grid[row][col] == EMPTY) {
            player2Grid[row][col] = O;
            return "Player 1 misses!";
        } else if (validCoord(row, col) && player2Grid[row][col] == SHIP) {
            player2Grid[row][col] = X;
            player2ShipsRemaining--;
            return "Player 1 hits!";
        }
    } else {
        if (validCoord(row, col) && player1Grid[row][col] == EMPTY) {
            player1Grid[row][col] = O;
            return "Player 2 misses!";
        } else if (validCoord(row, col) && player1Grid[row][col] == SHIP) {
            player1Grid[row][col] = X;
            player1ShipsRemaining--;
            return "Player 2 hits!";
        }
    }
    return "Invalid move!";
}

int Game::getCurrentPlayer() {
    return currentPlayer;
}

int Game::status() {
    if (player1ShipsRemaining == 0) {
        return PLAYER_2_WINS;
    } else if (player2ShipsRemaining == 0) {
        return PLAYER_1_WINS;
    }
    return ONGOING;
}

void Game::printGrid(int grid[5][5], bool hideShips) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (hideShips && grid[i][j] == SHIP) {
                std::cout << ". ";
            } else if (grid[i][j] == X) {
                std::cout << "X ";
            } else if (grid[i][j] == O) {
                std::cout << "O ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

int (*Game::getPlayer1Grid())[5] {
    return player1Grid;
}

int (*Game::getPlayer2Grid())[5] {
    return player2Grid;
}

bool Game::validCoord(int row, int col) const {
    return row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE;
}
