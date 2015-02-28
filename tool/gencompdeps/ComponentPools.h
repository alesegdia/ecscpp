
#pragma once

#include "Components.h"

#include <rztl/pool.h>
template <typename T> using Pool = rztl::Pool<T>;

typedef Pool<RenderComponent> CRenderPool;
typedef Pool<TransformComponent> CTransformPool;
typedef Pool<RelativeTransformComponent> CRelativeTransformPool;
typedef Pool<PlayerComponent> CPlayerPool;
typedef Pool<PhysicComponent> CPhysicPool;
typedef Pool<HealthComponent> CHealthPool;
typedef Pool<InputComponent> CInputPool;