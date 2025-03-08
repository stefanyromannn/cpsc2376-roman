#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

const int SIZE = 5;

vector<vector<char>> board;
int playerScores[2] = {0, 0};

void makeBoard() {
    int rows = SIZE * 2 - 1;
    int cols = SIZE * 2 - 1;

    board.resize(rows, vector<char>(cols, ' '));

    for (int i = 0; i < rows; i += 2) {
        for (int j = 0; j < cols; j += 2) {
            board[i][j] = '.';  
        }
    }
}

void displayBoard() {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

bool drawLine(int row, int col, string direction) {
    if (direction == "horizontal") {
        if (row % 2 == 0 && col + 1 < SIZE * 2 - 1) {
            if (board[row][col + 1] == '-') {
                return false;
            }
            board[row][col + 1] = '-';
            return true;
        }
    } else if (direction == "vertical") {
        if (col % 2 == 0 && row + 1 < SIZE * 2 - 1) {
            if (board[row + 1][col] == '|') {
                return false;
            }
            board[row + 1][col] = '|';
            return true;
        }
    }
    return false;
}

bool getInput(int& row, int& col, string& direction) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter your move (row, column, direction [horizontal/vertical]): ";
    std::cout.flush(); 

    char comma; 
    std::cin >> row >> comma >> col >> comma >> direction;

    if (row < 1 || col < 1 || row > SIZE || col > SIZE) {
        std::cout << "Invalid row or column! Please try again." << std::endl;
        return false;
    }

    if (direction != "horizontal" && direction != "vertical") {
        std::cout << "Invalid direction! Please enter 'horizontal' or 'vertical'." << std::endl;
        return false;
    }

    return true;
}

bool gameStatus() {
    for (int row = 1; row < SIZE * 2 - 2; row += 2) {
        for (int col = 1; col < SIZE * 2 - 2; col += 2) {
            if (board[row - 1][col] != '-' || 
                board[row + 1][col] != '-' ||
                board[row][col - 1] != '|' ||
                board[row][col + 1] != '|') {
                return false;
            }
        }
    }
    return true;  
}

void playGame() {
    int row, col;
    string direction;
    int currentPlayer = 0;

    std::cout << "Welcome to Dots and Boxes!" << std::endl;
    displayBoard();  
    
    while (true) {
        std::cout << "Player " << currentPlayer + 1 << "'s turn." << std::endl;

        bool validMove = false;
        while (!validMove) {
            if (!getInput(row, col, direction)) {
                continue;
            }

            
            row = (row - 1) * 2; 
            col = (col - 1) * 2;

            
            if (drawLine(row, col, direction)) {
                std::cout << "Move successful!" << std::endl;
                validMove = true;

                
                playerScores[currentPlayer]++;

              
                currentPlayer = (currentPlayer + 1) % 2;
            } else {
                std::cout << "Invalid move! Please try again." << std::endl;
            }
        }

        displayBoard(); 

    
        if (gameStatus()) {
            break;
        }
    }

    
    std::cout << "Game Over!" << std::endl;
    std::cout << "Player 1 Score: " << playerScores[0] << std::endl;
    std::cout << "Player 2 Score: " << playerScores[1] << std::endl;
    if (playerScores[0] > playerScores[1]) {
        std::cout << "Player 1 wins!" << std::endl;
    } else if (playerScores[1] > playerScores[0]) {
        std::cout << "Player 2 wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }
}

int main() {
    makeBoard(); 
    playGame(); 
    return 0;
}