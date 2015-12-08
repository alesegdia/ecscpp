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

void Entity::onCreate()
{
    alive = true;
}

ctflags_t Entity::getFlags()
{
    return m_flags;
}

bool Entity::all(ctflags_t flags)
{
    return ((m_flags & flags) == m_flags);
}

void Entity::clearComponents()
{
}

void Entity::cleanUp()
{
}

void Entity::setActive(bool alive)
{
    this->alive = alive;
}

void Entity::Destroy()
{
    alive = false;
}

bool Entity::isAlive()
{
    return alive;
}
