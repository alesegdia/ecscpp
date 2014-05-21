#include "TransformComponent.h"
#include "ComponentPools.h"

void TransformComponent::setPosition(int x, int y)
{
	_position.x = x;
	_position.y = y;
}

void TransformComponent::cleanUp()
{
	Locator<CTransformPool>::get()->release(getHandler());
}
