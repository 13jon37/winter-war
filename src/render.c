#include "include/render.h"

void do_render(render_T* r)
{
  SDL_SetRenderDrawColor(r->renderer, 255, 0, 255, 255);

  SDL_RenderClear(r->renderer);

  SDL_SetRenderDrawColor(r->renderer, 255, 0, 255, 255);

  SDL_RenderPresent(r->renderer);
}
