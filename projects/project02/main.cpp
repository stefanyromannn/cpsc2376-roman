#include "game.h"
#include <iostream>

int main() {
    Game game;
    int row, col;

    while (game.status() == ONGOING) {
        std::cout << game;
        std::cout << "Enter coordinates to fire (row col): ";
        std::cin >> row >> col;
        game.play(row, col);
    }

    if (game.status() == PLAYER_1_WINS)
        std::cout << "Player 1 wins!\n";
    else if (game.status() == PLAYER_2_WINS)
        std::cout << "Player 2 wins!\n";

    return 0;
}

