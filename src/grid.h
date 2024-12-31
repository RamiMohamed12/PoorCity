#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>

#define CELL_SIZE 50
#define MAP_WIDTH 1920 * 10 // 10 screens wide
#define MAP_HEIGHT 1080 * 10 // 10 screens tall

typedef struct {
    int x, y; // Top-left corner of the camera (visible area)
    int width, height; // Camera size (matches screen size)
} Camera;

void draw_grid(SDL_Renderer *renderer, Camera camera);

#endif

