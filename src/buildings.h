#ifndef BUILDINGS_H
#define BUILDINGS_H
#include "game_data.h"
#include "resources.h"

Buildings init_buildings();
int construct_building(Buildings *buildings, Resources *resources, const char *building_type);

#endif

