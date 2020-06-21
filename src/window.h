#pragma once
#include <SDL2/SDL_video.h>
#include "settings.h"

class LyrWindow {
    public:
        SDL_Window* m_window = NULL;
        SDL_GLContext m_glcontext = NULL;

        bool create(LyrSettings* settings);
        void destroy();

        void clear();
        void swap();
};