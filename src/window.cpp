#include <SDL.h>
#include "settings.h"
#include "window.h"


bool LyrWindow::create(LyrSettings* settings) {
    m_window = SDL_CreateWindow(
        "Lyra",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        settings->screenWidth(),
        settings->screenHeight(),
        SDL_WINDOW_OPENGL | (settings->fullscreen() && SDL_WINDOW_FULLSCREEN)
    );

    if (m_window == NULL) {
        // In the case that the window could not be made...
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        return false;
    }

    m_surface = SDL_GetWindowSurface(m_window);
    SDL_FillRect(m_surface, NULL, SDL_MapRGB(m_surface->format, 0, 0, 0));
    SDL_UpdateWindowSurface(m_window);

    return true;
}


void LyrWindow::destroy() {
    SDL_DestroyWindow(m_window);
}