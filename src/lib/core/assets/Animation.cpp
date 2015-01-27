
#include "Animation.h"

Animation::Animation ()
{
	 // ctor
}

Animation::~Animation ()
{
	 // dtor
}

bool Animation::Prepare( int num_frames, int num_plays )
{
	bool retcode = false;
	if( _frames.size() == 0 )
	{
		_frames.resize( num_frames );
		_numPlays = num_plays;
	}
	return retcode;
}

void Animation::Reset( Animation::Data& data )
{
	data.currentFrame = 0;
	data.currentFrameTimer = _frames[0].frameDuration;
	data.numPlays = _numPlays;
	data.lastPlay = 0;
}

void Animation::Update( sf::Time& delta, Animation::Data& data )
{

}

