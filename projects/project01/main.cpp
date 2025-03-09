#include <iostream>
#include <vector>
#include <string>
#include <limits>

const int SIZE = 5;

void makeBoard(std::vector<std::vector<char>>& board) {
    int rows = SIZE * 2 - 1;
    int cols = SIZE * 2 - 1;
    board.assign(rows, std::vector<char>(cols, ' '));

    for (int i = 0; i < rows; i += 2) {
        for (int j = 0; j < cols; j += 2) {
            board[i][j] = '.';
        }
    }
}

void displayBoard(const std::vector<std::vector<char>>& board, const std::vector<int>& playerScores) {
    std::cout << "\nCurrent Board:\n";
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Score - Player 1: " << playerScores[0] << " | Player 2: " << playerScores[1] << "\n";
}

bool drawLine(std::vector<std::vector<char>>& board, int row, int col, const std::string& direction, int currentPlayer, std::vector<int>& playerScores) {
    bool scored = false;
    char playerMark = (currentPlayer == 0) ? '1' : '2';

    if (direction == "horizontal" && row % 2 == 0 && col + 1 < SIZE * 2 - 1) {
        if (board[row][col + 1] == '-') return false;
        board[row][col + 1] = '-';
    } else if (direction == "vertical" && col % 2 == 0 && row + 1 < SIZE * 2 - 1) {
        if (board[row + 1][col] == '|') return false;
        board[row + 1][col] = '|';
    } else {
        return false;
    }

 
    for (int r = 1; r < SIZE * 2 - 2; r += 2) {
        for (int c = 1; c < SIZE * 2 - 2; c += 2) {
            if (board[r][c] == ' ' && board[r - 1][c] == '-' && board[r + 1][c] == '-' && board[r][c - 1] == '|' && board[r][c + 1] == '|') {
                board[r][c] = playerMark;
                playerScores[currentPlayer]++;
                scored = true;
            }
        }
    }
    return scored;
}

bool getInput(int& row, int& col, std::string& direction) {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter your move (row, column, direction [horizontal/vertical]): ";
    std::cout.flush();

    char comma;
    std::cin >> row >> comma >> col >> comma >> direction;

    if (row < 1 || col < 1 || row > SIZE || col > SIZE || (direction != "horizontal" && direction != "vertical")) {
        std::cout << "Invalid input! Try again.\n";
        return false;
    }
    return true;
}

bool gameStatus(const std::vector<std::vector<char>>& board) {
    for (int row = 1; row < SIZE * 2 - 2; row += 2) {
        for (int col = 1; col < SIZE * 2 - 2; col += 2) {
            if (board[row][col] == ' ') return false;
        }
    }
    return true;
}

void playGame() {
    std::vector<std::vector<char>> board;
    std::vector<int> playerScores(2, 0);
    makeBoard(board);
    int currentPlayer = 0;

    std::cout << "Welcome to Dots and Boxes!\n";
    displayBoard(board, playerScores);

    while (!gameStatus(board)) {
        int row, col;
        std::string direction;

        std::cout << "Player " << currentPlayer + 1 << "'s turn.\n";
        if (!getInput(row, col, direction)) continue;

        row = (row - 1) * 2;
        col = (col - 1) * 2;

        if (drawLine(board, row, col, direction, currentPlayer, playerScores)) {
            std::cout << "Player " << currentPlayer + 1 << " scored a point!\n";
        } else {
            currentPlayer = (currentPlayer + 1) % 2;
        }
        displayBoard(board, playerScores);
    }

    std::cout << "Game Over!\n";
    std::cout << "Player 1 Score: " << playerScores[0] << "\n";
    std::cout << "Player 2 Score: " << playerScores[1] << "\n";
    if (playerScores[0] > playerScores[1]) {
        std::cout << "Player 1 wins!\n";
    } else if (playerScores[1] > playerScores[0]) {
        std::cout << "Player 2 wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }
}

int main() {
    playGame();
    return 0;
}