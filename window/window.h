#include <SDL2/SDL.h>

#define WIN_TITLE "Learning Graphics"
#define WIN_WIDTH 640
#define WIN_HEIGHT 480

#define TARGET_FPS 60
#define FRAME_DELAY (1000 / TARGET_FPS)  // ~16ms per frame

void destroy_and_quit(SDL_Window *window, SDL_Renderer *renderer);
