
#pragma once

#include "ComponentPools.h"

class ComponentPoolHolder {
public:

    ComponentPoolHolder()
    { 
		Locator<CRenderPool>::set(&renderpool);
		Locator<CTransformPool>::set(&transformpool);
		Locator<CPlayerPool>::set(&playerpool);
		Locator<CRigidBodyPool>::set(&rigidbodypool);
		Locator<CShapePool>::set(&shapepool);
    }

private: 
	CRenderPool renderpool;
	CTransformPool transformpool;
	CPlayerPool playerpool;
	CRigidBodyPool rigidbodypool;
	CShapePool shapepool;

};