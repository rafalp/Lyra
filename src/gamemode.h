#pragma once
#include <vector>
#include "entity.h"

class LyrGameMode {
    public:
        std::vector<LyrEntity*> m_entities;

        void onTick() {};
        void render() {};
        void destroy() {};
};