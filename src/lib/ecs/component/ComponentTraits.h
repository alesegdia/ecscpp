
#pragma once

#include <cstdint>
#include <cmath>

typedef std::uint32_t ctflags_t;
typedef std::uint32_t ctindex_t;

class ComponentTraits
{
public:
	template <typename T>
	static ctflags_t GetFlag() {
		static const ctflags_t flag = pow(2, ComponentTraits::GetIndex<T>());
		return flag;
	}

	template <typename T>
	static ctflags_t GetIndex() {
		static const ctindex_t index = nextTypeIndex++;
		return index;
	}

	static ctflags_t GetNumComponents() {
		return nextTypeIndex;
	}

	template <class First, class... Rest>
	static ctflags_t ConstructFlags()
	{
		static const ctflags_t flags = ComponentTraits::GetFlag<First>() | ComponentTraits::GetFlag<Rest...>();
		return flags;
	}

	template <class T>
	static ctflags_t ConstructFlags()
	{
		return ComponentTraits::GetFlag<T>();
	}

private:
	static ctflags_t nextTypeIndex;
};


