#pragma once
#ifndef GAME_CLOCK_H

	#define GAME_CLOCK_H
	#include <SFML\System\Clock.hpp>

	class GameClock
	{
		public:
			GameClock();
			~GameClock();

			void LoopStart();

			const sf::Time& GetDeltaTime();

		private:
			sf::Clock _clock;
			sf::Time _lastTime;


	};

#endif // !GameClock
