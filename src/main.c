#include <stdio.h>

#include "include/renderwindow.h"

int main(int argc, char* argv[])
{
    render_T* graphics = init_window("Winter War", DEF_WIND_WIDTH, DEF_WIND_HEIGHT);
    
    game_loop(graphics);
    
    return 0;
}
