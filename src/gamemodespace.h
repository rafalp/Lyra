#pragma once
#include "entities.h"
#include "gamemode.h"
#include "systeminput.h"

class LyrGameModeSpace : public LyrGameMode
{
public:
    LyrSystemInput *m_input;

    void create();
    void destroy();
    bool tick();
    void render();

private:
    float m_rotx = 0.0;
    float m_roty = 0.0;
};
