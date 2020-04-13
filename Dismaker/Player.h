#pragma once
#ifndef PLAYER_H
	
	#define PLAYER_H
	#include <string>

	class RenderBridge;

	class Player
	{
		public:
			Player(const char* name);
			Player();
			~Player();

			void RenderGreeting(RenderBridge* renderer);

		private:
			std::string _name;
	};

#endif // !PLAYER_H
