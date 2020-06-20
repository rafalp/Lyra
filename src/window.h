#pragma once
#include <SDL.h>
#include "settings.h"

class LyrWindow {
    public:
        SDL_Window* m_window = NULL;
        SDL_Surface* m_surface = NULL;

        bool create(LyrSettings* settings);
        void destroy();
};