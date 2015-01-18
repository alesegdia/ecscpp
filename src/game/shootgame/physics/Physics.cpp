
#include "Physics.h"

Physics::Physics ()
{
	 // ctor
}

Physics::~Physics ()
{
	 // dtor
}

void Physics::Prepare()
{
	world = new b2World(b2Vec2(0,0));
}

b2World* Physics::GetWorld()
{
	return this->world;
}

b2Body* Physics::CreateTileBody( float tilew, float tileh )
{
	return CreateRectBody( tilew, tileh, b2_dynamicBody );
}

b2Body* Physics::CreateRectBody( float width, float height, b2BodyType type )
{
	// create body
	b2BodyDef bodydef;
	bodydef.position.SetZero();
	bodydef.type = type;
	b2Body* body = world->CreateBody(&bodydef);

	// create rect shape
	b2PolygonShape rect_shape;
	rect_shape.SetAsBox(width, height);

	// attach rect shape to body
	body->CreateFixture( &rect_shape, 0.0f ); // 2nd, density

	return body;
}

b2Body* Physics::CreateCircleBody( float radius, b2BodyType type )
{
	// create body
	b2BodyDef bodydef;
	bodydef.position.SetZero();
	bodydef.type = type;
	b2Body* body = world->CreateBody(&bodydef);

	// create circle shape
	b2CircleShape circle_shape;
	circle_shape.m_p.Set(0,0);
	circle_shape.m_radius = radius;

	// attach rect shape to body
	body->CreateFixture( &circle_shape, 0.0f ); // 2nd, density

	return body;
}
