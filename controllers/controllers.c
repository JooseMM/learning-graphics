#include <SDL2/SDL.h>
#include "../draw/draw.h"

#define MOVEMENT_STEPS 10

void set_controllers(SDL_Rect *player, SDL_Renderer *renderer, SDL_KeyCode key, int *running) {
 switch (key) {
  case SDLK_ESCAPE:
      *running = 0;
  case SDLK_j:
      draw_character(player, renderer, MOVEMENT_STEPS);
    break;
  case SDLK_k:
      draw_character(player, renderer, -MOVEMENT_STEPS);
      break;
  default:
      break;
 }
}
