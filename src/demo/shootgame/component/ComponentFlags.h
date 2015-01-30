
#pragma once

#include <cstdint>
#include <ecs/component/ComponentFlags.h>
#include "Components.h"
#include "ComponentsDecl.h"

typedef std::uint32_t ctflags_t;

template <>
struct component_flags<RenderComponent>
{ static const ctflags_t flags = 1; };

template <>
struct component_flags<TransformComponent>
{ static const ctflags_t flags = 2; };

template <>
struct component_flags<PlayerComponent>
{ static const ctflags_t flags = 4; };

template <>
struct component_flags<PhysicComponent>
{ static const ctflags_t flags = 8; };

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