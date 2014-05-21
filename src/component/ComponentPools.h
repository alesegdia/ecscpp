#ifndef __COMPONENTPOOLS_H__
#define __COMPONENTPOOLS_H__

#include "Pool.h"
#include "Components.h"

#define DEFAULT_POOL_SZ 128

template <class T>
struct pool_size
{ static const size_t size = DEFAULT_POOL_SZ; };

/*
template <>
struct pool_size<SomeType>
{ static const size = 1234; };
*/

typedef Pool<RenderComponent,pool_size<RenderComponent>::size> CRenderPool;
typedef Pool<TransformComponent,pool_size<TransformComponent>::size> CTransformPool;
typedef Pool<PlayerComponent,pool_size<PlayerComponent>::size> CPlayerPool;

#endif
