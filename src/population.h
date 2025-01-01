#ifndef POPULATION_H
#define POPULATION_H
#include "game_data.h"
Population init_population(int starting_population);
void assign_population(Population *pop, const char *task, int amount);
void update_population(Population *pop, int elapsed_time);

#endif

