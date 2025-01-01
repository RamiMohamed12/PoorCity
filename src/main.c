#include <SDL2/SDL.h>
#include "grid.h"
#include "ui.h"
#include "save_load.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Resource Management Game",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize game variables
    Population population = {10, 10, 0, 0};
    Resources resources = {100, 0, 0, 0};
    Buildings buildings = {0, 0, 0, 0};

    int running = 1;
    SDL_Event event;
    int camera_x = 0, camera_y = 0; // Camera offsets

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }

            // Handle key presses
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE: // Quit the game
                        running = 0;
                        break;
                    case SDLK_s: // Save game
                        save_game("savegame.txt", &population, &resources, &buildings);
                        break;
                    case SDLK_l: // Load game
                        if (load_game("savegame.txt", &population, &resources, &buildings)) {
                            printf("Game successfully loaded.\n");
                        }
                        break;
                }
            }

            // Handle mouse movement for scrolling
            if (event.type == SDL_MOUSEMOTION) {
                camera_x -= event.motion.xrel;
                camera_y -= event.motion.yrel;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255); // Earth-green background
        SDL_RenderClear(renderer);

        // Render game elements
        render_grid(renderer, camera_x, camera_y); // Render grid with camera offset
        render_ui(renderer, &population, &resources, &buildings); // Render UI stats

        // Update screen
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // Approx. 60 FPS
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

