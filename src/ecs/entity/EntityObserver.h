#ifndef __ENTITYOBSERVER_H__
#define __ENTITYOBSERVER_H__

#include "Entity.h"
#include "eid_t.h"

class EntityObserver
{
public:
	virtual ~EntityObserver() {	}

	/* Observer interface */
	virtual void added(eid_t e)	{ }
	virtual void deleted(eid_t e) {	}
};

#endif
