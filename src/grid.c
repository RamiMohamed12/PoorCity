#include "grid.h"

void draw_grid(SDL_Renderer *renderer, int screen_width, int screen_height) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color

    // Draw vertical lines
    for (int x = 0; x <= screen_width; x += CELL_SIZE) {
        SDL_RenderDrawLine(renderer, x, 0, x, screen_height);
    }

    // Draw horizontal lines
    for (int y = 0; y <= screen_height; y += CELL_SIZE) {
        SDL_RenderDrawLine(renderer, 0, y, screen_width, y);
    }
}

