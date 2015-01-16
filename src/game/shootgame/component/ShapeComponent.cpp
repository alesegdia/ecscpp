
#include "ShapeComponent.h"
#include <core/util/Locator.h>
#include "ComponentPools.h"

void ShapeComponent::cleanUp()
{
	Locator<CShapePool>::get()->release(getHandler());
}
