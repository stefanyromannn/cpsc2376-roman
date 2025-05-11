#include "game.h"

Game::Game() : gameStatus(Status::ONGOING), playerTurn(true) {
    board = std::vector<std::vector<BoardElement>>(3, std::vector<BoardElement>(3, BoardElement::EMPTY));
}

void Game::play(int row, int col) {
    if (board[row][col] == BoardElement::EMPTY && gameStatus == Status::ONGOING) {
        board[row][col] = playerTurn ? BoardElement::PLAYER_1 : BoardElement::PLAYER_2;
        switchTurn();
    }
}

Status Game::status() const {
    // Check for a winner or draw logic (simplified here)
    // This is where you can add the game-ending conditions
    return gameStatus;
}

void Game::display() const {
    for (const auto& row : board) {
        for (const auto& elem : row) {
            if (elem == BoardElement::EMPTY) std::cout << "-";
            else if (elem == BoardElement::PLAYER_1) std::cout << "X";
            else std::cout << "O";
        }
        std::cout << std::endl;
    }
}

void Game::switchTurn() {
    playerTurn = !playerTurn;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    game.display();
    return os;
}
