#include "ui.h"
#include <SDL2/SDL.h>
#include <stdio.h>

void handle_input(int key, Population *pop, Resources *resources, Buildings *buildings) {
    switch (key) {
        case SDLK_1: { // Assign population to gather food
            printf("Assign how many people to gather food: ");
            int num;
            scanf("%d", &num);
            assign_population(pop, "food", num);
            break;
        }
        case SDLK_2: { // Construct a building
            printf("Enter building type (house, castle, shop, marketplace): ");
            char building_type[20];
            scanf("%s", building_type);
            construct_building(buildings, resources, building_type);
            break;
        }
        default:
            printf("Invalid input.\n");
    }
}

void render_ui(SDL_Renderer *renderer, Population *pop, Resources *resources, Buildings *buildings) {
    // Placeholder: Render resource and population stats
    printf("Population: %d (Unassigned: %d)\n", pop->total_population, pop->unassigned);
    printf("Resources - Food: %d, Wood: %d, Stone: %d, Concrete: %d\n",
           resources->food, resources->wood, resources->stone, resources->concrete);
    printf("Buildings - Houses: %d, Castles: %d, Shops: %d, Marketplaces: %d\n",
           buildings->houses, buildings->castles, buildings->shops, buildings->marketplaces);
}

