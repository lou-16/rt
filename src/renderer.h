#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>

typedef struct Renderer_t {
    SDL_Window* window;
    SDL_Renderer* renderer;
} Renderer_t;

#endif