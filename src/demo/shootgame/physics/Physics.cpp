
#include "Physics.h"

Physics::Physics ()
{
	 // ctor
}

Physics::~Physics ()
{
	 // dtor
	 delete ddraw;
}

void Physics::Prepare(float unitsToMeters)
{
	world = new b2World(b2Vec2(0,0));
	this->unitsToMeters = unitsToMeters;
}


void Physics::ActiveDebugDraw( sf::RenderWindow* win )
{
	ddraw = new DebugDraw(*win, 1.f/this->unitsToMeters);
	this->world->SetDebugDraw(ddraw);
	ddraw->SetFlags( b2Draw::e_shapeBit );
}

b2World* Physics::GetWorld()
{
	return this->world;
}

float Physics::ProjUnit( float qtt )
{
	return qtt * unitsToMeters;
}

b2Body* Physics::CreateRectBody( float x, float y, float width, float height, b2BodyType type )
{
	// create body
	b2BodyDef bodydef;
	bodydef.position.Set( ProjUnit(x), ProjUnit(y) );
	bodydef.type = type;
	b2Body* body = world->CreateBody(&bodydef);

	// create rect shape
	b2PolygonShape rect_shape;
	rect_shape.SetAsBox(ProjUnit(width), ProjUnit(height));

	// attach rect shape to body
	body->CreateFixture( &rect_shape, 0.0f ); // 2nd, density

	return body;
}

b2Body* Physics::CreateCircleBody( float x, float y, float radius, b2BodyType type )
{
	// create body
	b2BodyDef bodydef;
	bodydef.position.Set( ProjUnit(x), ProjUnit(y) );
	bodydef.type = type;
	b2Body* body = world->CreateBody(&bodydef);

	// create circle shape
	b2CircleShape circle_shape;
	circle_shape.m_p.Set(0,0);
	circle_shape.m_radius = ProjUnit(radius);

	// attach rect shape to body
	body->CreateFixture( &circle_shape, 0.0f ); // 2nd, density

	return body;
}

