#include "game.h"

Game::Game() : xTurn(true), currentStatus(ONGOING) {
    for (auto& row : board) {
        row.fill(EMPTY);
    }
}

void Game::play(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != EMPTY || currentStatus != ONGOING)
        return;

    board[row][col] = xTurn ? X : O;

    if (isWinningMove(board[row][col])) {
        currentStatus = xTurn ? PLAYER_X_WINS : PLAYER_O_WINS;
    } else if (isDraw()) {
        currentStatus = DRAW;
    }

    xTurn = !xTurn;
}

Game::Status Game::status() const {
    return currentStatus;
}

bool Game::isWinningMove(Cell player) const {
    // Check rows, columns, diagonals
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool Game::isDraw() const {
    for (const auto& row : board) {
        for (Cell cell : row) {
            if (cell == EMPTY)
                return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    for (const auto& row : game.board) {
        for (const auto& cell : row) {
            switch (cell) {
                case Game::EMPTY: os << "."; break;
                case Game::X:     os << "X"; break;
                case Game::O:     os << "O"; break;
            }
            os << " ";
        }
        os << "\n";
    }
    return os;
}
