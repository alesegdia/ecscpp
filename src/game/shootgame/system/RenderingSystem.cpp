
#include "RenderingSystem.h"
#include "../component/Components.h"

RenderingSystem::RenderingSystem ()
{
	setFlags(construct_flags<RenderComponent,PhysicComponent>::flags);
}

RenderingSystem::~RenderingSystem ()
{
	 // dtor
}

void RenderingSystem::Prepare( sf::RenderWindow* window )
{
	_window = window;
	_rtex.create(window->getSize().x,window->getSize().y);
	_rtex2.create(window->getSize().x,window->getSize().y);
	if(!shader.loadFromFile("fshad.frag", sf::Shader::Fragment))
	{
		printf("ERROR AL CARGAR EL SHADER!");
	}
	else
	{
		shader.setParameter("texture", sf::Shader::CurrentTexture);
	}

	if(!shader2.loadFromFile("fshad2.frag", sf::Shader::Fragment))
	{
		printf("ERROR AL CARGAR EL SHADER!");
	}
	else
	{
		shader2.setParameter("texture", sf::Shader::CurrentTexture);
	}
}

void RenderingSystem::process()
{

}

void RenderingSystem::draw()
{
	_rtex.clear();
	RenderList(RenderComponent::ZORDER_0);
	RenderList(RenderComponent::ZORDER_1);
	RenderList(RenderComponent::ZORDER_2);
	_rtex.display();
	sf::Sprite sprite(_rtex.getTexture());
	//sprite.setPosition(0,0);
	_rtex2.draw( sprite, &shader );
	sf::Sprite sprite2(_rtex2.getTexture());
	_window->draw(sprite2, &shader2);
}

void RenderingSystem::process(Entity* e)
{
	RenderComponent* rc = e->getComponent<RenderComponent>();
	TransformComponent* tc = e->getComponent<TransformComponent>();
	PhysicComponent* phc = e->getComponent<PhysicComponent>();
	//rc->getSprite()->setPosition(tc->_position.x, tc->_position.y);
	rc->getSprite()->setPosition(phc->body->GetPosition().x * 32.f, phc->body->GetPosition().y * 32.f );
	//_window->draw(*(rc->getSprite()));
	_rtex.draw(*(rc->getSprite()));
}

void RenderingSystem::RenderList( RenderComponent::ZOrder order )
{
	for( auto it : _renderLists[order] )
	{
		process(it);
	}
}

#include <string.h>
const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

void RenderingSystem::addEntity(Entity* e)
{
	printf("ADDED TO RSYS! eflags: %s\nsflags: %s\n", byte_to_binary(e->getFlags()), byte_to_binary(this->_flags));
	RenderComponent* rc = e->getComponent<RenderComponent>();
	_renderLists[rc->zorder].push_back(e);
}

void RenderingSystem::rmEntity(Entity* e)
{
	// optimization: use vector and divide steps:
	// 		* step: rmEntity -> annotates entity to remove for each renderlist
	// 		* post step: removes all annotated entities from renderlists
	RenderComponent* rc = e->getComponent<RenderComponent>();
	_renderLists[rc->zorder].remove(e);
}
