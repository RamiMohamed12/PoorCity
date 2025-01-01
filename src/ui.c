#include "ui.h"
#include "render_text.h"

void render_building_progress(SDL_Renderer *renderer, int x, int y, float progress) {
    SDL_Rect progressBar = {x, y, 100, 10};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black border
    SDL_RenderFillRect(renderer, &progressBar);

    progressBar.w = (int)(progress * 100);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for progress
    SDL_RenderFillRect(renderer, &progressBar);
}

void render_building_message(SDL_Renderer *renderer, const char *message, int x, int y) {
    SDL_Color white = {255, 255, 255, 255};
    render_text(renderer, message, x, y, white);
}

