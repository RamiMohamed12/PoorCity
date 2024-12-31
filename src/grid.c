#include "grid.h"

void draw_grid(SDL_Renderer *renderer, Camera camera) {
    SDL_Color green = {34, 139, 34, 255}; // Green terrain color

    // Draw only the visible portion of the map
    for (int y = camera.y; y < camera.y + camera.height; y += CELL_SIZE) {
        for (int x = camera.x; x < camera.x + camera.width; x += CELL_SIZE) {
            // Only render cells within the map boundaries
            if (x < MAP_WIDTH && y < MAP_HEIGHT) {
                SDL_SetRenderDrawColor(renderer, green.r, green.g, green.b, green.a);

                SDL_Rect cell = {
                    x - camera.x, // Adjust position relative to the camera
                    y - camera.y, 
                    CELL_SIZE, 
                    CELL_SIZE
                };
                SDL_RenderFillRect(renderer, &cell);
            }
        }
    }

    // Draw grid lines
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black lines
    for (int x = camera.x; x < camera.x + camera.width; x += CELL_SIZE) {
        SDL_RenderDrawLine(renderer, x - camera.x, 0, x - camera.x, camera.height);
    }
    for (int y = camera.y; y < camera.y + camera.height; y += CELL_SIZE) {
        SDL_RenderDrawLine(renderer, 0, y - camera.y, camera.width, y - camera.y);
    }
}

