#include "render_grid.h"

void render_grid(SDL_Renderer *renderer, int camera_x, int camera_y, float zoom_level) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    int grid_size = 50 * zoom_level; // Scale grid size with zoom

    for (int x = -camera_x % grid_size; x < 800; x += grid_size) {
        SDL_RenderDrawLine(renderer, x, 0, x, 600);
    }

    for (int y = -camera_y % grid_size; y < 600; y += grid_size) {
        SDL_RenderDrawLine(renderer, 0, y, 800, y);
    }
}

