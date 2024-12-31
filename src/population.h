#ifndef POPULATION_H
#define POPULATION_H

typedef struct {
    int total_population;
    int assigned_to_food;
    int assigned_to_wood;
    int assigned_to_stone;
    int assigned_to_concrete;
    int unassigned;
    int spawn_timer; // Timer for population growth (2 minutes)
} Population;

Population init_population(int starting_population);
void assign_population(Population *pop, const char *task, int amount);
void update_population(Population *pop, int elapsed_time);

#endif

