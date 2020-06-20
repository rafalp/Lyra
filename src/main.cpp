#include <stdio.h>
#include <SDL.h>
#include "settings.h"
#include "window.h"

int quit() {
    SDL_Quit();
    return 1;
}

int main(int argc, char* args[]) {
    SDL_Event e;

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    LyrSettings* settings = new LyrSettings();
    if (!settings->init()) {
        return quit();
    }

    LyrWindow* window = new LyrWindow();
    if (!window->create(settings)) {
        return quit();
    }
    
    bool runloop = true;
    while (runloop) {
        while (SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                runloop = false;
            }
            if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                runloop = false;
            }
        }
    }

    SDL_Quit();

    window->destroy();
    delete window;
    delete settings;
    return 0;
}