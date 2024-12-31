#include "buildings.h"
#include <stdio.h>
#include <string.h>

Buildings init_buildings() {
    Buildings b = {0, 0, 0, 0}; // No buildings initially
    return b;
}

int construct_building(Buildings *buildings, Resources *resources, const char *building_type) {
    if (strcmp(building_type, "house") == 0) {
        if (resources->wood >= 10) {
            resources->wood -= 10;
            buildings->houses++;
            printf("House constructed! Total houses: %d\n", buildings->houses);
            return 1;
        } else {
            printf("Not enough wood for a house.\n");
            return 0;
        }
    } else if (strcmp(building_type, "castle") == 0) {
        if (resources->wood >= 1000 && resources->stone >= 1000 && resources->concrete >= 1000) {
            resources->wood -= 1000;
            resources->stone -= 1000;
            resources->concrete -= 1000;
            buildings->castles++;
            printf("Castle constructed! Total castles: %d\n", buildings->castles);
            return 1;
        } else {
            printf("Not enough resources for a castle.\n");
            return 0;
        }
    } else if (strcmp(building_type, "shop") == 0) {
        if (resources->wood >= 10 && resources->stone >= 5) {
            resources->wood -= 10;
            resources->stone -= 5;
            buildings->shops++;
            printf("Shop constructed! Total shops: %d\n", buildings->shops);
            return 1;
        } else {
            printf("Not enough resources for a shop.\n");
            return 0;
        }
    } else if (strcmp(building_type, "marketplace") == 0) {
        if (resources->wood >= 200 && resources->stone >= 100 && resources->concrete >= 15) {
            resources->wood -= 200;
            resources->stone -= 100;
            resources->concrete -= 15;
            buildings->marketplaces++;
            printf("Marketplace constructed! Total marketplaces: %d\n", buildings->marketplaces);
            return 1;
        } else {
            printf("Not enough resources for a marketplace.\n");
            return 0;
        }
    } else {
        printf("Unknown building type: %s\n", building_type);
        return 0;
    }
}

