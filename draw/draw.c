#include <SDL2/SDL.h>
#include "../window/window.h"


void draw_character(SDL_Rect *player, SDL_Renderer *renderer, Sint8 y) {
 int tmp = player->y + y;
  if(tmp >= 0 && tmp <= WIN_HEIGHT - player->h) {
   player->y += y;
  }
  SDL_RenderDrawRect(renderer, player);
  SDL_SetRenderDrawColor(renderer, 255,255,255,255);
  SDL_RenderFillRect(renderer, player);
}
