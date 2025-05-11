#include <iostream>
#include "game.h"

int main() {
    Game game;

    while (!game.isGameOver()) {
        std::cout << "Entering the game loop..." << std::endl;
        std::cout << "Player " << game.getCurrentPlayer() << "'s turn!" << std::endl;
        
        std::cout << "Player 1's grid:" << std::endl;
        game.printGrid(game.getPlayer1Grid(), true);
        std::cout << "Player 2's grid:" << std::endl;
        game.printGrid(game.getPlayer2Grid(), true);

        int row, col;
        std::cout << "Enter row and column: ";
        std::cin >> row >> col;

        std::string result = game.play(row, col);
        std::cout << result << std::endl;
        game.switchTurn();

        if (game.status() == Game::PLAYER_1_WINS) {
            std::cout << "Player 1 wins!" << std::endl;
        } else if (game.status() == Game::PLAYER_2_WINS) {
            std::cout << "Player 2 wins!" << std::endl;
        }
    }

    return 0;
}

