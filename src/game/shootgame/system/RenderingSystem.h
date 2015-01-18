#ifndef __RENDERINGSYSTEM_H__
#define __RENDERINGSYSTEM_H__

#include <ecs/system/EntityProcessingSystem.h>
#include "../component/ComponentFlags.h"
#include <stdinc.h>
#include <list>

class RenderingSystem : public EntityProcessingSystem
{
public:


	RenderingSystem();
	~RenderingSystem();


	void process(Entity* e);
	void process() override;

	void Prepare(sf::RenderWindow *window);

	void RenderList( RenderComponent::ZOrder order );

private:

	void addEntity(Entity* e) override;
	void rmEntity(Entity* e) override;

	sf::RenderWindow* _window;
	std::list<Entity*> _renderLists[RenderComponent::NUM_ZORDERS];
};

#endif
