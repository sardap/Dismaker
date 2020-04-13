#pragma once
#ifndef INPUT_STATE_H

	#define INPUT_STATE_H

	struct InputState
	{
		enum Value
		{
			Released,
			Down,
			Pressed
		};
	};

#endif // !INPUT_STATE_H
