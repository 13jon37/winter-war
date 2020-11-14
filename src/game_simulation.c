#include "include/game_simulation.h"

bool event_processes(void)
{
    SDL_Event event;
    bool running  = true;
    
    if (SDL_PollEvent(&event))
    {
        switch (event.type) 
        {
            case SDL_QUIT: {
                running = false;
            } break;
            
        }
        
        // NOTE(1337): Add keyboard events
        
    }
    
    return running;
}