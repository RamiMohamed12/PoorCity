#ifndef RESOURCES_H
#define RESOURCES_H

typedef struct {
    int food;
    int wood;
    int stone;
    int concrete;
} Resources;

Resources init_resources(int food, int wood, int stone, int concrete);
void gather_resources(Resources *res, const char *type, int amount);
void consume_food(Resources *res, int amount);

#endif

