#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include "population.h"
#include "resources.h"
#include "buildings.h"

void render_ui(SDL_Renderer *renderer, Population *pop, Resources *resources, Buildings *buildings);
void render_building_progress(SDL_Renderer *renderer, int x, int y, float progress);
void render_building_message(SDL_Renderer *renderer, const char *message, int x, int y);

#endif

