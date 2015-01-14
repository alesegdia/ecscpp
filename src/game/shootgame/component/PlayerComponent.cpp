#include "PlayerComponent.h"
#include <core/util/Locator.h>
#include "ComponentPools.h"

void PlayerComponent::cleanUp()
{
	Locator<CPlayerPool>::get()->release(getHandler());
}
