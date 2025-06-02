#include <SDL2/SDL.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include "./window/window.h"
#include "./controllers/controllers.h"
#include "./draw/draw.h"


int main () {
 SDL_Window *window = SDL_CreateWindow(WIN_TITLE, 0, 0, WIN_WIDTH, WIN_HEIGHT, 0);
 SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
 SDL_Event event;
 int running = 1;

 SDL_Rect player = { 0, 0, 20, 60 };

 if(SDL_Init(SDL_INIT_VIDEO)) {
  printf("%s", SDL_GetError());
  destroy_and_quit(window, renderer);
  return 1;
 }


 if(!window || !renderer) {
  printf("%s",SDL_GetError());
  destroy_and_quit(window, renderer);
  return 1;
 }


 while(running) {
  Uint32 startf = SDL_GetTicks();

  SDL_SetRenderDrawColor(renderer, 0,0,0,255);
  SDL_RenderClear(renderer);

  draw_character(&player, renderer, 0);

  while(SDL_PollEvent(&event)) {
   switch (event.type) {
    case SDL_KEYDOWN:
     set_controllers(
       &player,
       renderer,
       event.key.keysym.sym,
       &running);
     break;
    case SDL_QUIT:
     running = 0;
     break;
   }
  }

  /*  Update the screen  */
  SDL_RenderPresent(renderer);

  Uint32 endf = SDL_GetTicks() - startf;

  if(endf > FRAME_DELAY) {
   SDL_Delay(FRAME_DELAY - endf);
  }
 }

 /*  Destroy everything before exit  */
 destroy_and_quit(window, renderer);
 return 0;
}
