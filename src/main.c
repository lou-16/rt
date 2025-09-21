#include <SDL3/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) != true){
        printf("sdlinit error %s\n", SDL_GetError());
    }

    SDL_Window* window = SDL_CreateWindow("title", 800, 600, SDL_WINDOW_RESIZABLE);

    if(!window) {
        printf("sdl create window error %s\n", SDL_GetError());
        SDL_Quit();
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if(!renderer) {
        printf("sdl renderer error %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    int running = 1;
    SDL_Event event;

    while(running) {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_EVENT_QUIT){
                running = 0;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0,0,255);
        SDL_FRect rect = {200, 150, 400, 300};
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
