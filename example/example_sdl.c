#include <SDL.h>
#include <stdbool.h>

// Use the ARGB pixel format
#define PNTR_PIXELFORMAT_ARGB

// Support the default font
#define PNTR_SUPPORT_DEFAULT_FONT

// This must be loaded first
#define PNTR_IMPLEMENTATION
#include "pntr.h"

// load pntr-font
#define PNTR_FONT_IMPLEMENTATION
#include "pntr-font.h"

// this is just for web demo
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

SDL_Window* window;
SDL_Surface* screen;
SDL_Surface* surface;
pntr_image* canvas;

bool shouldClose = false;

void mainloop() {
  SDL_Event event;
  while (SDL_PollEvent(&event) != 0) {
    switch (event.type) {
      case SDL_QUIT:
        shouldClose = true;
        break;
    }
  }

  if (shouldClose) {
    SDL_FreeSurface(surface);

    // Unload
    // TODO

    SDL_DestroyWindow(window);
    SDL_Quit();
  } else {
    // Update
    // TODO

    SDL_BlitSurface(surface, NULL, screen, NULL);
    SDL_UpdateWindowSurface(window);
  }
}

int main() {
  canvas = pntr_new_image(400, 225);
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  window = SDL_CreateWindow("pntr-font: Examples - SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, canvas->width, canvas->height, SDL_WINDOW_SHOWN);
  screen = SDL_GetWindowSurface(window);
  surface = SDL_CreateRGBSurfaceWithFormatFrom((void*)canvas->data, canvas->width, canvas->height, 8, canvas->pitch, SDL_PIXELFORMAT_ARGB8888);

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(mainloop, 0, 1);
#else
  while (!shouldClose) {
    mainloop();
    SDL_Delay(16);
  }
#endif
}