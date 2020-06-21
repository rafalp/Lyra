#pragma once
#include "gamemode.h"

class LyrGameModeSpace: public LyrGameMode {
    public:
        float m_rotation = 1.0;

        void onTick();
        void render();
};