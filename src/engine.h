#ifndef ENGINE_H
#define ENGINE_H

/*
    the engine is the superset module that contains the 
    math module, and links the scene manager and renderer 
    together, while maintaining data structures for both
*/
#include <SDL3\SDL.h>
#include "manager.h"
#include "renderer.h"

struct Window {
    SDL_Window* window;
    int x;
    int y;
    int h;
    int w;
    char* title;
};

struct Renderer {
    enum backend {
        SDL = 0
    };
    Renderer_t* internal_renderer_ptr;    
};

Renderer* getCurrentRenderer();
Renderer* initialiseRenderer();


#endif