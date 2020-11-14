#include <stdio.h>

#include "include/renderwindow.h"
#include "include/game_simulation.h"

// Constant
scene_manager_T* SCENE_MANAGER;

int main(int argc, char* argv[])
{
    render_T* window  = init_window("Winter War", DEF_WIND_WIDTH, DEF_WIND_HEIGHT);
    
    SCENE_MANAGER = init_scene_manager();
    register_scenes(SCENE_MANAGER);
    
    bool running = true;
    
    while (running)
    {
        // Inlcudes quit condtionals and will probably include key events
        running = event_processes();    
        
        do_render(window);
    }
    
    clean_up(window);
    
    return 0;
}
