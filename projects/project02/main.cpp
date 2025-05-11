#include <iostream>
#include "game.h"

int main() {
    Game game;
    int row, col;

    while (game.status() == Status::ONGOING) {
        std::cout << game;  // Displays the board
        std::cout << "Enter row and column (0-2): ";
        std::cin >> row >> col;

        game.play(row, col);
    }

    std::cout << "Game Over!" << std::endl;
    return 0;
}
