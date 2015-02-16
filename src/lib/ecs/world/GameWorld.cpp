
#include "GameWorld.h"

Entity* GameWorld::CreateEntity()
{
	Entity* ret = NULL;
	if( _eidpool.Size() <= 0 )
	{
		printf("NO MORE IDS!!\n");
	}
	else
	{
		ret = Locator<Pool<Entity>>::get()->Create();
		ret->OnCreate();
		eid_t entityID = _eidpool.checkOut();
		ret->setEID(entityID);
	}
	assert(ret != NULL);
	return ret;
}
