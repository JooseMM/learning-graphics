#include <SDL2/SDL.h>
#include <stdio.h>

#define WIN_TITLE "Learning Graphics"
#define WIN_WIDTH 640
#define WIN_HEIGHT 480

int main () {
 SDL_Window *window = NULL;
 SDL_Renderer *renderer = NULL;

 window = SDL_CreateWindow(WIN_TITLE, 0, 0, WIN_WIDTH, WIN_HEIGHT, 0);
 renderer = SDL_CreateRenderer(window, -1, 0);

 if(!window || !renderer) {
  printf("%s",SDL_GetError());
 }

 SDL_SetRenderDrawColor(renderer, 255,255,255,255);
 SDL_RenderClear(renderer);

 SDL_SetRenderDrawColor(renderer, 0,0,0,255);
 SDL_RenderDrawLine(renderer, 10, 0, 50, 0);

 /*  Update the screen  */
 SDL_RenderPresent(renderer);
 SDL_Delay(1000);
 /*  Destroy everything before exit  */
 SDL_DestroyWindow(window);
 SDL_DestroyRenderer(renderer);

 SDL_Quit();

 return 0;
}
