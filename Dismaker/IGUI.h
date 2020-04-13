#pragma once	
#ifndef IGUI_H

	#define IGUI_H
	#include "Renderable.h"

	class IGUI : public Renderable
	{
		public:
			IGUI(GameState::Value gameState = GameState::Game);
			virtual ~IGUI() = 0;
	};

#endif // !IGUI_H
