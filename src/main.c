#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "render_grid.h"
#include "ui.h"
#include "population.h"
#include "resources.h"
#include "buildings.h"

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window *window = SDL_CreateWindow("Resource Management Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Camera and zoom level
    int camera_x = 0, camera_y = 0;
    float zoom_level = 1.0;

    // Game data
    Population population = { .current = 10, .max = 10 };
    Resources resources = { .wood = 100, .stone = 50, .food = 30 };
    Buildings buildings = { .houses = 0, .castles = 0, .shops = 0, .markets = 0 };

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_w: camera_y -= 10; break; // Move up
                    case SDLK_s: camera_y += 10; break; // Move down
                    case SDLK_a: camera_x -= 10; break; // Move left
                    case SDLK_d: camera_x += 10; break; // Move right
                    case SDLK_e: // Build a house
                        if (resources.wood >= 10 && resources.stone >= 5) {
                            resources.wood -= 10;
                            resources.stone -= 5;
                            buildings.houses++;
                        }
                        break;
                    case SDLK_q: running = 0; break; // Quit game
                }
            }
        }

        // Update population and check win/lose conditions
        update_population(&population, &buildings);
        if (population.current >= 100) {
            printf("You win! Population reached 100!\n");
            running = 0;
        }
        if (resources.wood <= 0 && resources.stone <= 0 && resources.food <= 0) {
            printf("You lost! No more resources!\n");
            running = 0;
        }

        // Render everything
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_grid(renderer, camera_x, camera_y, zoom_level);
        render_ui(renderer, &population, &resources, &buildings);

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
    return 0;
}

