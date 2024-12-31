#ifndef BUILDINGS_H
#define BUILDINGS_H

#include "resources.h"

typedef struct {
    int houses;
    int castles;
    int shops;
    int marketplaces;
} Buildings;

Buildings init_buildings();
int construct_building(Buildings *buildings, Resources *resources, const char *building_type);

#endif

