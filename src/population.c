#include "population.h"
#include <stdio.h>

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

void update_population(Population *pop, int elapsed_time) {
    pop->spawn_timer -= elapsed_time;
    if (pop->spawn_timer <= 0) {
        pop->spawn_timer = 120; // Reset timer
        pop->total_population++;
        pop->unassigned++;
    }
}

