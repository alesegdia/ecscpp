
#include "Spritesheet.h"

Spritesheet::Spritesheet ()
{
	 // ctor
}

Spritesheet::~Spritesheet ()
{
	 // dtor
}

bool Spritesheet::Prepare( sf::Texture* tex, sf::Vector2i size )
{
	bool retcode = false;
	if( _rects.size() == 0 )
	{
		_tex = tex;
		_rects.resize( size.x * size.y );
		_tileSize.x = _tex->getSize().x / size.x;
		_tileSize.y = _tex->getSize().y / size.y;
		for( int rect_index = 0; rect_index < size.x * size.y; rect_index++ )
		{
			int x, y;
			x = rect_index % size.x;
			y = floor( rect_index / size.x );
			_rects[rect_index] = sf::IntRect(
					_tileSize.x * x,
					_tileSize.y * y,
					_tileSize.x, _tileSize.y);
		}
		retcode = true;
	}
	return retcode;
}

const sf::IntRect& Spritesheet::GetFrame( int num_frame )
{
	return _rects[num_frame];
}

sf::Texture* Spritesheet::GetTexture()
{
	return _tex;
}

