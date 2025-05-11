#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

enum class Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum class BoardElement { EMPTY, PLAYER_1, PLAYER_2 };

class Game {
public:
    Game();  // Constructor
    void play(int row, int col);  // Function to play a move
    Status status() const;  // Function to check the status of the game
    void display() const;  // Function to display the board

    // Overloading << operator to print the game board
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
    std::vector<std::vector<BoardElement>> board;
    Status gameStatus;
    bool playerTurn;  // true for player 1, false for player 2

    void switchTurn();  // Switch between players after a move
};

#endif // GAME_H
