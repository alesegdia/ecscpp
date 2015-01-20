
#pragma once

#include <Box2D/Box2D.h>

class Physics {

public:

	Physics ();
	virtual ~Physics ();

	void Prepare(float unitsToMeters=1.f/32.f);
	b2World* GetWorld();

	b2Body* CreateRectBody( float x, float y, float width, float height, b2BodyType type=b2_staticBody );
	b2Body* CreateCircleBody( float x, float y, float radius, b2BodyType type=b2_staticBody );

private:

	inline float ProjUnit( float qtt );


	b2World* world;
	float unitsToMeters;

};
