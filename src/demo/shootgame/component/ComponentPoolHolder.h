
#pragma once

#include "ComponentPools.h"

class ComponentPoolHolder {
public:

    ComponentPoolHolder()
    { 
		Locator<CRenderPool>::set(&renderpool);
		Locator<CTransformPool>::set(&transformpool);
		Locator<CPlayerPool>::set(&playerpool);
		Locator<CPhysicPool>::set(&physicpool);
    }

private: 
	CRenderPool renderpool;
	CTransformPool transformpool;
	CPlayerPool playerpool;
	CPhysicPool physicpool;

};