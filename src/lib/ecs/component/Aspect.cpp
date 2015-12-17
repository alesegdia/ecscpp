#include "Aspect.h"



bool Aspect::all(ctflags_t flags)
{
	return (flags & m_allFilter) == m_allFilter;
}

bool Aspect::any(ctflags_t flags)
{
	return (flags & m_anyFilter) != 0 || m_anyFilter == 0;
}

bool Aspect::none(ctflags_t flags)
{
	return (flags & m_noneFilter) == 0;
}

bool Aspect::fits(ctflags_t flags)
{
	return all(flags) && any(flags) && none(flags);
}
