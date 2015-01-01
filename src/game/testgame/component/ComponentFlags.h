#ifndef __COMPONENTFLAGS_H__
#define __COMPONENTFLAGS_H__

#include <cstdint>
#include <ecs/component/ComponentFlags.h>
#include "../component/RenderComponent.h"
#include "../component/TransformComponent.h"

/*
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
*/

typedef std::uint32_t ctflags_t;

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

template <class... Ts>
struct construct_flags;

template <class First, class... Rest>
struct construct_flags<First, Rest...>
{
	static const ctflags_t flags =
		component_flags<First>::flags |
		construct_flags<Rest...>::flags;
};

template <class T>
struct construct_flags<T>
{ static const ctflags_t flags = component_flags<T>::flags; };
#endif
