#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include "game.h"

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create SDL Window
    SDL_Window* window = SDL_CreateWindow("Battleship",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, 0);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create SDL Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize the game
    Game game;
    bool running = true;
    SDL_Event e;
    int lastPlayer = -1; // Track the last player for conditional debugging

    // Main game loop
    while (running && !game.isGameOver()) {
        // Handle events
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
                running = false;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                // Convert mouse click to grid coordinates
                int x = e.button.x / 80;
                int y = e.button.y / 80;

                
                std::cout << "Mouse clicked at (" << x << ", " << y << ")" << std::endl;

                std::string result = game.play(y, x);
                std::cout << result << std::endl;

            
                if (result != "Invalid coordinates!" && result != "Already attacked!") {
                    game.switchTurn();
                }
            }
        }

    
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        SDL_RenderClear(renderer);

    
        if (game.getCurrentPlayer() != lastPlayer) {
            std::cout << "Rendering Player " << game.getCurrentPlayer() << "'s grid." << std::endl;
            lastPlayer = game.getCurrentPlayer();
        }

        if (game.getCurrentPlayer() == 1) {
            game.renderGrid(game.getPlayer1Grid(), false, renderer);
        }
        else {
            game.renderGrid(game.getPlayer2Grid(), true, renderer);
        }


        SDL_RenderPresent(renderer);
        SDL_Delay(16); 
    }

    if (game.isGameOver()) {
        if (game.getCurrentPlayer() == 1) {
            std::cout << "Player 2 wins!" << std::endl;
        }
        else {
            std::cout << "Player 1 wins!" << std::endl;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}