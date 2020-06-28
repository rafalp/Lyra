#pragma once
#include "entities.h"
#include "window.h"

class LyrGameMode
{
public:
    LyrEntities *m_entities;

    void create(){};
    void destroy(){};
    bool tick(){ return false; };
    void render(){};
};