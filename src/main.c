#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include "population.h"
#include "resources.h"
#include "buildings.h"
#include "game_rules.h"
#include "ui.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main(int argc, char *argv[]) {
    // SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("SDL Initialization Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Resource Management Game",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_FULLSCREEN);
    if (!window) {
        printf("Window Creation Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer Creation Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize game state
    Population population = init_population(10); // 10 starting population
    Resources resources = init_resources(100, 0, 0, 0); // 100 food, 0 other materials
    Buildings buildings = init_buildings();
    GameRules rules = init_game_rules();

    bool running = true;
    SDL_Event event;

    Uint32 last_update_time = SDL_GetTicks(); // Timer for updates

    while (running) {
        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                handle_input(event.key.keysym.sym, &population, &resources, &buildings);
            }
        }

        // Periodic updates
        Uint32 current_time = SDL_GetTicks();
        if (current_time - last_update_time >= 1000) { // 1-second updates
            update_game(&rules, &population, &resources, &buildings);
            last_update_time = current_time;
        }

        // Rendering
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);

        render_ui(renderer, &population, &resources, &buildings);

        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

