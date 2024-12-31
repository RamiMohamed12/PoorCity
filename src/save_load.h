#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "population.h"
#include "resources.h"
#include "buildings.h"

void save_game(const char *filename, Population *pop, Resources *resources, Buildings *buildings);
int load_game(const char *filename, Population *pop, Resources *resources, Buildings *buildings);

#endif

