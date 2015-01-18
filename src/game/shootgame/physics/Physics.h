
#pragma once

#include <Box2D/Box2D.h>

class Physics {

public:

	Physics ();
	virtual ~Physics ();

	void Prepare();
	b2World* GetWorld();

	b2Body* CreateTileBody( float tilew, float tileh );

private:

	b2Body* CreateRectBody( float width, float height, b2BodyType type=b2_staticBody );
	b2Body* CreateCircleBody( float radius, b2BodyType type=b2_staticBody );

	b2World* world;

};

