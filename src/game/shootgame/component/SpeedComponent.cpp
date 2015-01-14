
#include "SpeedComponent.h"
#include <core/util/Locator.h>
#include "ComponentPools.h"

void SpeedComponent::cleanUp()
{
	Locator<CSpeedPool>::get()->release(getHandler());
}
