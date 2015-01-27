
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

void Animation::SetFrame( int frame_seq, int frame_sheet, sf::Time duration )
{
	_frames[frame_seq].frameIndex = frame_sheet;
	_frames[frame_seq].frameDuration = duration;
}

void Animation::Reset( Animation::Data& data )
{
	data.currentFrame = 0;
	data.currentFrameTimer = _frames[0].frameDuration;
	data.numPlays = _numPlays;
	data.lastPlay = 0;
}

void Animation::Update( sf::Time& delta, Animation::Data& d )
{
	bool play = true;
	sf::Time rest = d.currentFrameTimer - delta;
	// if we have to change to reset the animation
	if( rest < sf::Time::Zero && d.currentFrame == _frames.size() - 1 )
	{
		// keep playing if infinite, stop if not
		play = d.numPlays < 0;

		// but if there are still plays, we compute it
		if( d.numPlays > 0 )
		{
			// we finished this play, next!
			d.numPlays--;
			d.currentFrame = 0;
			d.currentFrameTimer = _frames[0].frameDuration - rest;
		}
	}

	if( play )
	{
		if( rest < sf::Time::Zero )
		{
			d.currentFrame = (d.currentFrame + 1) % _frames.size();
			d.currentFrameTimer = -rest;
		}
		else
		{
			d.currentFrameTimer -= rest;
		}
	}
}

