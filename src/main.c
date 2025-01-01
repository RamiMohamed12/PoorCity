#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include "grid.h"
#include "ui.h"
#include "population.h"
#include "resources.h"
#include "buildings.h"
#include "render_text.h"

// Screen Dimensions
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Resource Management Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_FULLSCREEN
    );

    if (!window) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Game Variables
    Population population = { .current = 10, .max = 10 };
    Resources resources = { .food = 100, .wood = 0, .stone = 0, .concrete = 0 };
    Buildings buildings = { .houses = 0, .castles = 0, .shops = 0, .markets = 0 };

    int camera_x = 0, camera_y = 0;
    float zoom_level = 1.0f;
    const float ZOOM_SPEED = 0.1f;

    Uint32 last_food_update = SDL_GetTicks();
    bool running = true;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                // Camera Movement
                if (event.key.keysym.sym == SDLK_w) camera_y -= 10;
                if (event.key.keysym.sym == SDLK_s) camera_y += 10;
                if (event.key.keysym.sym == SDLK_a) camera_x -= 10;
                if (event.key.keysym.sym == SDLK_d) camera_x += 10;
            } else if (event.type == SDL_MOUSEWHEEL) {
                if (event.wheel.y > 0) zoom_level += ZOOM_SPEED;
                else if (event.wheel.y < 0) zoom_level -= ZOOM_SPEED;
                if (zoom_level < 0.5f) zoom_level = 0.5f;
            }
        }

        // Update food every 2 minutes
        Uint32 current_time = SDL_GetTicks();
        if (current_time - last_food_update >= 120000) {
            resources.food -= 1;
            last_food_update = current_time;

            if (resources.food <= 0) {
                game_over(renderer);
            }
        }

        // Win Condition
        if (buildings.castles > 0) {
            victory(renderer);
        }

        // Render the game
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_grid(renderer, camera_x, camera_y, zoom_level);
        render_ui(renderer, &population, &resources, &buildings);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

