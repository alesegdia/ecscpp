#include "Entity.h"

Entity::Entity()
    : m_components(25, nullptr)
{
    m_flags = 0;
    alive = true;
}

Entity::~Entity()
{
}

eid_t Entity::getEID()
{
    return m_eid;
}

ctflags_t Entity::getFlags()
{
    return m_flags;
}

void Entity::destroy()
{
    alive = false;
}

bool Entity::isAlive()
{
    return alive;
}
