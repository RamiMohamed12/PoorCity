#include <SDL2/SDL.h>
#include <stdbool.h>
#include "grid.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define CAMERA_SPEED 10

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Resource Management Game",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_FULLSCREEN);

    if (!window) {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Could not create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Camera camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                // Move camera with arrow keys or WASD
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                    case SDLK_w:
                        if (camera.y > 0) camera.y -= CAMERA_SPEED;
                        break;
                    case SDLK_DOWN:
                    case SDLK_s:
                        if (camera.y + camera.height < MAP_HEIGHT) camera.y += CAMERA_SPEED;
                        break;
                    case SDLK_LEFT:
                    case SDLK_a:
                        if (camera.x > 0) camera.x -= CAMERA_SPEED;
                        break;
                    case SDLK_RIGHT:
                    case SDLK_d:
                        if (camera.x + camera.width < MAP_WIDTH) camera.x += CAMERA_SPEED;
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);

        // Draw the visible portion of the map
        draw_grid(renderer, camera);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

