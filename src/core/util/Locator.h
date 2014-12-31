#ifndef __LOCATOR_H__
#define __LOCATOR_H__

#include "AssetHolder.h"

template<typename Service>
class Locator
{
public:
	static void set(Service* service)
	{
		_service = service;
	}

	static Service* get()
	{
		return _service;
	}

private:
	static Service* _service;
};

template <typename Service>
Service* Locator<Service>::_service;



#endif
