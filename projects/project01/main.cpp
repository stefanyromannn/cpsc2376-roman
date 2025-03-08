#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

const int SIZE = 5;  // 5x5 grid

vector<vector<char>> board;
int playerScores[2] = {0, 0};

void makeBoard() {
    int rows = SIZE * 2 - 1;
    int cols = SIZE * 2 - 1;

    board.resize(rows, vector<char>(cols, ' '));

    // Place dots on the board (using even rows and columns)
    for (int i = 0; i < rows; i += 2) {
        for (int j = 0; j < cols; j += 2) {
            board[i][j] = '.';  // Place dot at every even index
        }
    }
}

void displayBoard() {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool drawLine(int row, int col, string direction) {
    if (direction == "horizontal") {
        if (row % 2 == 0 && col + 1 < SIZE * 2 - 1) {
            if (board[row][col + 1] == '-') {
                return false;  // Already a horizontal line
            }
            board[row][col + 1] = '-';
            return true;
        }
    } else if (direction == "vertical") {
        if (col % 2 == 0 && row + 1 < SIZE * 2 - 1) {
            if (board[row + 1][col] == '|') {
                return false;  // Already a vertical line
            }
            board[row + 1][col] = '|';
            return true;
        }
    }
    return false;
}

bool getInput(int& row, int& col, string& direction) {
    // Clear the input buffer by ignoring any residual characters
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore leftover characters

    cout << "Enter your move (row, column, direction [horizontal/vertical]): ";
    cout.flush();  // Ensure the prompt is printed immediately

    char comma;  // To consume the commas between inputs
    cin >> row >> comma >> col >> comma >> direction;

    // Check if the row and col are valid (1-based indexing)
    if (row < 1 || col < 1 || row > SIZE || col > SIZE) {
        cout << "Invalid row or column! Please try again." << endl;
        return false;
    }

    // Check if direction is valid
    if (direction != "horizontal" && direction != "vertical") {
        cout << "Invalid direction! Please enter 'horizontal' or 'vertical'." << endl;
        return false;
    }

    return true;
}

bool gameStatus() {
    // Check if all the squares are completed
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
    return true;  // All squares are completed
}

void playGame() {
    int row, col;
    string direction;
    int currentPlayer = 0;  // Player 1 starts (0 = Player 1, 1 = Player 2)

    // Print the welcome message at the start
    cout << "Welcome to Dots and Boxes!" << endl;

    // Immediately display the board after the game starts
    displayBoard();  // Display the initial empty board

    // Start the game loop
    while (true) {
        // Print the current player's turn prompt
        cout << "Player " << currentPlayer + 1 << "'s turn." << endl;

        // Immediately prompt for the player's move
        bool validMove = false;
        while (!validMove) {
            if (!getInput(row, col, direction)) {
                // If invalid input, the prompt will be shown again
                continue;
            }

            // Adjust the row and col for the grid indexing (dots are at even indices)
            row = (row - 1) * 2;  // Convert user input to the correct grid coordinates
            col = (col - 1) * 2;

            if (drawLine(row, col, direction)) {
                cout << "Move successful!" << endl;
                validMove = true;

                // Alternate player
                currentPlayer = (currentPlayer + 1) % 2;
            } else {
                cout << "Invalid move! Please try again." << endl;
            }
        }

        // Display the updated board after each valid move
        displayBoard();

        // Check if the game is over
        if (gameStatus()) {
            break;
        }
    }

    // Declare winner and end game
    cout << "Game Over!" << endl;
    cout << "Player 1 Score: " << playerScores[0] << endl;
    cout << "Player 2 Score: " << playerScores[1] << endl;
    if (playerScores[0] > playerScores[1]) {
        cout << "Player 1 wins!" << endl;
    } else if (playerScores[1] > playerScores[0]) {
        cout << "Player 2 wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}

int main() {
    makeBoard();  // Initialize board
    playGame();  // Start the game loop
    return 0;
}
