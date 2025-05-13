#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game() : player1ShipsRemaining(5), player2ShipsRemaining(5), currentPlayer(1) {
    std::srand(std::time(nullptr));

    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            player1Grid[i][j] = EMPTY;
            player2Grid[i][j] = EMPTY;
        }
    }


    placeShipsRandomly(player1Grid);
    placeShipsRandomly(player2Grid);
}

void Game::placeShipsRandomly(int grid[GRID_SIZE][GRID_SIZE]) {
    int shipsPlaced = 0;
    while (shipsPlaced < 5) {
        int row = std::rand() % GRID_SIZE;
        int col = std::rand() % GRID_SIZE;
        if (grid[row][col] == EMPTY) {
            grid[row][col] = SHIP;
            ++shipsPlaced;
        }
    }
}

bool Game::validCoord(int row, int col) const {
    return row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE;
}

std::string Game::play(int row, int col) {
    if (!validCoord(row, col)) {
        return "Invalid coordinates!";
    }

    int (*currentGrid)[GRID_SIZE] = (currentPlayer == 1) ? player2Grid : player1Grid;
    int& cell = currentGrid[row][col];

    if (cell == HIT || cell == MISS) {
        return "Already attacked!";
    }

    if (cell == SHIP) {
        cell = HIT;
        if (currentPlayer == 1) {
            --player2ShipsRemaining;
        }
        else {
            --player1ShipsRemaining;
        }
        return "Hit!";
    }
    else {
        cell = MISS;
        return "Miss!";
    }
}

void Game::switchTurn() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

bool Game::isGameOver() const {
    return player1ShipsRemaining == 0 || player2ShipsRemaining == 0;
}

int Game::getCurrentPlayer() const {
    return currentPlayer;
}

int (*Game::getPlayer1Grid())[GRID_SIZE] {
    return player1Grid;
}

int (*Game::getPlayer2Grid())[GRID_SIZE] {
    return player2Grid;
}

void Game::renderGrid(int grid[GRID_SIZE][GRID_SIZE], bool hideShips, SDL_Renderer* renderer) const {
    int cellSize = 80;
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            SDL_Rect cell = { col * cellSize, row * cellSize, cellSize, cellSize };

            if (grid[row][col] == SHIP && !hideShips) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); 
            }
            else if (grid[row][col] == HIT) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            else if (grid[row][col] == MISS) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); 
            }
            else {
                SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); 
            }

            SDL_RenderFillRect(renderer, &cell);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
            SDL_RenderDrawRect(renderer, &cell);
        }
    }
}
