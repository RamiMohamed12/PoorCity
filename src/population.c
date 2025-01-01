#include "population.h"
#include <stdio.h>
#include<string.h>
Population init_population(int starting_population) {
    Population pop = {
        .total_population = starting_population,
        .assigned_to_food = 0,
        .assigned_to_wood = 0,
        .assigned_to_stone = 0,
        .assigned_to_concrete = 0,
        .unassigned = starting_population,
        .spawn_timer = 120 // 2 minutes
    };
    return pop;
}

void assign_population(Population *pop, const char *task, int amount) {
    if (amount > pop->unassigned) {
        printf("Not enough unassigned population!\n");
        return;
    }

    if (strcmp(task, "food") == 0) {
        pop->assigned_to_food += amount;
    } else if (strcmp(task, "wood") == 0) {
        pop->assigned_to_wood += amount;
    } else if (strcmp(task, "stone") == 0) {
        pop->assigned_to_stone += amount;
    } else if (strcmp(task, "concrete") == 0) {
        pop->assigned_to_concrete += amount;
    }

    pop->unassigned -= amount;
}

void update_population(Population *pop, Buildings *buildings) {
    pop->max = buildings->houses * 5; // Each house supports 5 people
    if (pop->current < pop->max) {
        pop->current++; // Increment population if there's capacity
    }
}


