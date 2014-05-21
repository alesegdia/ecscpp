#include "Component.h"

Component::Component()
{

}

Component::~Component()
{

}


void Component::cleanUp()
{

}

size_t Component::getHandler()
{
	return Poolable::getHandler();
}

void Component::setHandler(size_t handler)
{
	Poolable::setHandler(handler);
}
