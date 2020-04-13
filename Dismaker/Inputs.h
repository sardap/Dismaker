#pragma once
#ifndef INPUTS_H

	#define INPUTS_H

	struct Input
	{
		enum Value
		{
			Up,
			Down,
			Left,
			Right,
			Enter,
			Escape,

			Count
		};
	};
	
#endif // !INPUTS_H
