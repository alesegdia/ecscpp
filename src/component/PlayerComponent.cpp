#include "PlayerComponent.h"
#include "Locator.h"
#include "ComponentPools.h"

void PlayerComponent::cleanUp()
{
	Locator<CPlayerPool>::get()->release(getHandler());
}
