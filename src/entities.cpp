#include "entities.h"

size_t LyrEntities::createEntity()
{
    size_t size = m_entities.size();

    if (size == 0)
    {
        m_entities.reserve(1024);
        m_entities.push_back(true);
        return size;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (!m_entities[i])
        {
            m_entities[i] = true;
            return i;
        }
    }

    if (m_entities.capacity() == size)
    {
        m_entities.reserve(1024);
    }

    m_entities.push_back(true);
    return size;
}

void LyrEntities::destroyEntity(size_t entity)
{
    m_entities[entity] = false;
}