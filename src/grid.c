#include "grid.h"

void render_grid(SDL_Renderer *renderer, int camera_x, int camera_y, float zoom_level) {
    const int TILE_SIZE = (int)(50 * zoom_level); // Adjust tile size based on zoom
    const int GRID_WIDTH = 100;  // Number of tiles horizontally
    const int GRID_HEIGHT = 100; // Number of tiles vertically

    for (int row = 0; row < GRID_HEIGHT; ++row) {
        for (int col = 0; col < GRID_WIDTH; ++col) {
            SDL_Rect tile = {
                col * TILE_SIZE - camera_x,
                row * TILE_SIZE - camera_y,
                TILE_SIZE,
                TILE_SIZE
            };

            // Set earth-like green color
            SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255); // Earth-green
            SDL_RenderFillRect(renderer, &tile);

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black border
            SDL_RenderDrawRect(renderer, &tile);
        }
    }
}

