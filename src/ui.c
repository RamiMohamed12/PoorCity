#include "ui.h"
#include "render_text.h"

void render_ui(SDL_Renderer *renderer, Population *pop, Resources *resources, Buildings *buildings) {
    SDL_Color white = {255, 255, 255};

    char message[128];
    snprintf(message, sizeof(message), "Population: %d / %d", pop->current, pop->max);
    render_text(renderer, message, 10, 10, 24, white);

    snprintf(message, sizeof(message), "Wood: %d | Stone: %d | Food: %d", resources->wood, resources->stone, resources->food);
    render_text(renderer, message, 10, 50, 24, white);

    snprintf(message, sizeof(message), "Houses: %d | Markets: %d", buildings->houses, buildings->markets);
    render_text(renderer, message, 10, 90, 24, white);
}



void game_over(SDL_Renderer *renderer) {
    SDL_Color red = {255, 0, 0, 255};
    render_text(renderer, "GAME OVER!", 400, 300, 36, red);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
}

void victory(SDL_Renderer *renderer) {
    SDL_Color green = {0, 255, 0, 255};
    render_text(renderer, "VICTORY!", 400, 300, 36, green);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
}

