#pragma once
#include "entities.h"
#include "gamemode.h"

class LyrGameModeSpace : public LyrGameMode
{
public:
    LyrEntities *m_entities;

    void create();
    void render();
};
