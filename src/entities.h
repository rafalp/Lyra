#pragma once
#include <vector>

class LyrEntities
{
public:
    std::vector<bool> m_entities = NULL;

    size_t createEntity();
    void destroyEntity(size_t entity);
};