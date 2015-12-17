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

void Entity::setEID(eid_t eid)
{
    m_eid = eid;
}

eid_t Entity::getEID()
{
    return m_eid;
}

ctflags_t Entity::getFlags()
{
    return m_flags;
}

void Entity::Destroy()
{
    alive = false;
}

bool Entity::isAlive()
{
    return alive;
}
