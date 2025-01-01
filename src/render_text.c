#include "render_text.h"

void render_text(SDL_Renderer *renderer, const char *text, int x, int y, int font_size, SDL_Color color) {
    TTF_Font *font = TTF_OpenFont("/usr/share/fonts/TTF/ZedMonoNerdFontPropo-ExtendedMedium.ttf", font_size);
    if (!font) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return;
    }

    SDL_Surface *text_surface = TTF_RenderText_Solid(font, text, color);
    if (!text_surface) {
        SDL_Log("Failed to create text surface: %s", TTF_GetError());
        TTF_CloseFont(font);
        return;
    }

    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    if (!text_texture) {
        SDL_Log("Failed to create text texture: %s", SDL_GetError());
        SDL_FreeSurface(text_surface);
        TTF_CloseFont(font);
        return;
    }

    SDL_Rect text_rect = {x, y, text_surface->w, text_surface->h};
    SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);

    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
    TTF_CloseFont(font);
}

