#ifndef UI_H
#define UI_H

#include "population.h"
#include "resources.h"
#include "buildings.h"

void handle_input(int key, Population *pop, Resources *resources, Buildings *buildings);
void render_ui(SDL_Renderer *renderer, Population *pop, Resources *resources, Buildings *buildings);

#endif

