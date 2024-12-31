#include "save_load.h"
#include <stdio.h>

void save_game(const char *filename, Population *pop, Resources *resources, Buildings *buildings) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Unable to save game to file: %s\n", filename);
        return;
    }

    // Save population data
    fprintf(file, "Population:%d %d %d %d\n", pop->total_population, pop->unassigned, pop->food_collectors, pop->material_collectors);

    // Save resources data
    fprintf(file, "Resources:%d %d %d %d\n", resources->food, resources->wood, resources->stone, resources->concrete);

    // Save buildings data
    fprintf(file, "Buildings:%d %d %d %d\n", buildings->houses, buildings->castles, buildings->shops, buildings->marketplaces);

    fclose(file);
    printf("Game saved to %s\n", filename);
}

int load_game(const char *filename, Population *pop, Resources *resources, Buildings *buildings) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to load game from file: %s\n", filename);
        return 0;
    }

    // Load population data
    fscanf(file, "Population:%d %d %d %d\n", &pop->total_population, &pop->unassigned, &pop->food_collectors, &pop->material_collectors);

    // Load resources data
    fscanf(file, "Resources:%d %d %d %d\n", &resources->food, &resources->wood, &resources->stone, &resources->concrete);

    // Load buildings data
    fscanf(file, "Buildings:%d %d %d %d\n", &buildings->houses, &buildings->castles, &buildings->shops, &buildings->marketplaces);

    fclose(file);
    printf("Game loaded from %s\n", filename);
    return 1;
}

