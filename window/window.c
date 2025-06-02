#include <SDL2/SDL.h>
#include "./window.h"

void destroy_and_quit(SDL_Window *window, SDL_Renderer *renderer) {
 SDL_DestroyWindow(window);
 SDL_DestroyRenderer(renderer);
 SDL_Quit();
}
