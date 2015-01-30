
#include "PhysicComponent.h"
#include "ComponentPools.h"
#include <core/util/Locator.h>

void PhysicComponent::cleanUp()
{
	Locator<CPhysicPool>::get()->release(getHandler());
}
