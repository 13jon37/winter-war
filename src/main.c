#include <stdio.h>

#include "include/render.h"
#include "include/scene_manager.h"
#include "include/scene_registry.h"

// Constant
scene_manager_T* SCENE_MANAGER;

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Failed to init video. Error: %s\n", SDL_GetError());
        return 1;
    }
    
    render_T* graphics = init_window("Winter War", DEF_WIND_WIDTH, DEF_WIND_HEIGHT);
    
    SCENE_MANAGER = init_scene_manager();
    register_scenes(SCENE_MANAGER);
    
    SDL_Event event;
    bool running = true;
    
    while (running)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) 
                running = false;
        }
        
        do_render(graphics);
    }
    
    clean_up(graphics);
    
    SDL_Quit();
    
    return 0;
}
