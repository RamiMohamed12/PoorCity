#include "resources.h"
#include <stdio.h>
#include<string.h>
Resources init_resources(int food, int wood, int stone, int concrete) {
    Resources res = {food, wood, stone, concrete};
    return res;
}

void gather_resources(Resources *res, const char *type, int amount) {
    if (strcmp(type, "food") == 0) {
        res->food += amount;
    } else if (strcmp(type, "wood") == 0) {
        res->wood += amount;
    } else if (strcmp(type, "stone") == 0) {
        res->stone += amount;
    } else if (strcmp(type, "concrete") == 0) {
        res->concrete += amount;
    }
}

void consume_food(Resources *res, int amount) {
    res->food -= amount;
    if (res->food < 0) res->food = 0;
}

