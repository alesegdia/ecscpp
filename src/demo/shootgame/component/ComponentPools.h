
#pragma once

#include <core/memory/Pool.h>
#include "Components.h"

#define DEFAULT_POOL_SZ 128

template <class T>
struct pool_size
{ static const size_t size = DEFAULT_POOL_SZ; };

typedef Pool<RenderComponent,pool_size<RenderComponent>::size> CRenderPool;
typedef Pool<TransformComponent,pool_size<TransformComponent>::size> CTransformPool;
typedef Pool<PlayerComponent,pool_size<PlayerComponent>::size> CPlayerPool;
typedef Pool<PhysicComponent,pool_size<PhysicComponent>::size> CPhysicPool;