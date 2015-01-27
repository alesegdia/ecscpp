
#pragma once

#include<string>

#include "Spritesheet.h"

class Animation {
public:

	struct Data {
		int currentFrame; 				// index of the current running frame
		sf::Time currentFrameTimer; 	// time that the current frame has been running
		int lastPlay; 					// is the last time this animation is played
		int numPlays; 					// number of times the animation will be played
	};

	struct Frame {
		int frameIndex; 				// the identifier number of this frame (spritesheet index)
		sf::Time frameDuration; 		// the time this frame should be running
	};

	Animation ();
	virtual ~Animation ();

	bool Prepare( int num_frames, int num_plays );
	void SetFrame( int frame_seq, int frame_sheet, float duration );

	void Reset( Animation::Data& data );
	void Update( sf::Time& delta, Animation::Data& data );

private:
	std::vector<Animation::Frame> _frames;
	int _numPlays;
};

