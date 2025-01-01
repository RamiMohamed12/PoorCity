#include "ui.h"
#include "render_text.h"

void render_ui(SDL_Renderer *renderer, Population *pop, Resources *resources, Buildings *buildings) {
    char buffer[128];
    SDL_Color white = {255, 255, 255, 255};

    // Render population
    snprintf(buffer, sizeof(buffer), "Population: %d (Unassigned: %d)", pop->total_population, pop->unassigned);
    render_text(renderer, buffer, 20, 20, white);

    // Render resources
    snprintf(buffer, sizeof(buffer), "Food: %d | Wood: %d | Stone: %d | Concrete: %d",
             resources->food, resources->wood, resources->stone, resources->concrete);
    render_text(renderer, buffer, 20, 50, white);

    // Render buildings
    snprintf(buffer, sizeof(buffer), "Houses: %d | Castles: %d | Shops: %d | Marketplaces: %d",
             buildings->houses, buildings->castles, buildings->shops, buildings->marketplaces);
    render_text(renderer, buffer, 20, 80, white);
}

void animate_resource_gathering(SDL_Renderer *renderer, int x, int y, const char *resource_type) {
    SDL_Color green = {0, 255, 0, 255};
    render_text(renderer, "+2", x, y, green); // Example: Floating "+2" effect
    SDL_Delay(200); // Temporary animation effect
}

