#ifndef __COMPONENTFLAGS_H__
#define __COMPONENTFLAGS_H__

#include <cstdint>
#include <ecs/component/ComponentFlags.h>
//#include "RenderComponent.h"
//#include "TransformComponent.h"

class RenderComponent;
class TransformComponent;
class PlayerComponent;



template <>
struct component_flags<RenderComponent>
{ static const ctflags_t flags = 0x00000001; };

template <>
struct component_flags<TransformComponent>
{ static const ctflags_t flags = 0x00000002; };

template <>
struct component_flags<PlayerComponent>
{ static const ctflags_t flags = 0x00000004; };


#endif
