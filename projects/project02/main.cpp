#include "game.h"
#include <iostream>

int main() {
    Game game;
    int row, col;

    while (game.status() == Game::ONGOING) {
        std::cout << game;
        std::cout << "Enter row and column (0-2): ";
        std::cin >> row >> col;
        game.play(row, col);
    }

    std::cout << game;
    Game::Status result = game.status();

    if (result == Game::PLAYER_X_WINS)
        std::cout << "Player X wins!\n";
    else if (result == Game::PLAYER_O_WINS)
        std::cout << "Player O wins!\n";
    else
        std::cout << "It's a draw!\n";

    return 0;
}