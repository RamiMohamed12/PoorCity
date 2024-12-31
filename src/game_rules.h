#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "population.h"
#include "resources.h"

typedef struct {
    int food_consumption_timer; // Timer for food consumption
    int food_multiplier;        // 10x population for expansion
    int game_over;              // 1 if game is over, 0 otherwise
} GameRules;

GameRules init_game_rules();
void update_game(GameRules *rules, Population *pop, Resources *resources, Buildings *buildings);

#endif

