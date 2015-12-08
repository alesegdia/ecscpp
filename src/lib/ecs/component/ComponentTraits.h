
#pragma once

#include <cstdint>
#include <cmath>

typedef std::uint32_t ctflags_t;
typedef std::uint32_t ctindex_t;

class ComponentTraits
{
public:

    template <typename T>
    static ctflags_t GetFlag()
    {
		static const ctflags_t flag = pow(2, ComponentTraits::GetIndex<T>());
		return flag;
	}

	template <typename T>
    static ctflags_t GetIndex()
    {
		static const ctindex_t index = nextTypeIndex++;
		return index;
	}

	static ctflags_t GetNumComponents() {
		return nextTypeIndex;
	}

    template <typename... Args>
    static ctflags_t BuildBits() {
        return ComponentBitsBuilder<Args...>::buildBits();
    }


private:
	static ctflags_t nextTypeIndex;

    template <typename... Rest>
    struct ComponentBitsBuilder;

    template <typename First, typename... Rest>
    struct ComponentBitsBuilder<First, Rest...>
    {
        static ctflags_t buildBits()
        {
            return GetFlag<First>() | ComponentBitsBuilder<Rest...>::buildBits();
        }
    };


};

template <>
struct ComponentTraits::ComponentBitsBuilder<>
{
    static ctflags_t buildBits()
    {
        return 0;
    }
};

