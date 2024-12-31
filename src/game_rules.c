#include "game_rules.h"
#include <stdio.h>

GameRules init_game_rules() {
    GameRules rules = {
        .food_consumption_timer = 120, // Food consumed every 2 minutes
        .food_multiplier = 10,
        .game_over = 0
    };
    return rules;
}

void update_game(GameRules *rules, Population *pop, Resources *resources, Buildings *buildings) {
    // Food consumption
    rules->food_consumption_timer--;
    if (rules->food_consumption_timer <= 0) {
        consume_food(resources, 1); // 1 food every 2 minutes per rules
        rules->food_consumption_timer = 120;

        // Check for population loss
        if (resources->food <= 0) {
            pop->total_population--;
            pop->unassigned--; // Decrement unassigned population first
            if (pop->total_population <= 0) {
                rules->game_over = 1;
                printf("Game Over: Your population has perished.\n");
                return;
            }
            printf("Population reduced to %d due to lack of food.\n", pop->total_population);
        }
    }

    // Population expansion check
    if (resources->food >= pop->total_population * rules->food_multiplier) {
        update_population(pop, 1); // Expand population if conditions are met
    }
}

