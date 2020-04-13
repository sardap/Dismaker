#pragma once
#ifndef SFML_MANAGER_H

	#define SFML_MANAGER_H
	#include <SFML\Graphics.hpp>
	#include "AudioManager.h"

	class SFMLManager
	{
		// STATIC SECTION
		public:
			static SFMLManager* GetInstane();

		private:
			static bool _singletonCreated;
			static SFMLManager* _singleton;

		// END OF STATIC SECTION

		public:
			SFMLManager();
			~SFMLManager();
			
			sf::RenderWindow* GetRenderWindow();
			sf::Window* GetWindow();
			AudioManager& GetAudioManager();
			sf::Event& GetEvent();
			void ProcessEvents();

			
		private:
			sf::Event _event;
			sf::RenderWindow* _window;
			AudioManager _audioManager;
	};

#endif // !SFML_MANAGER_H
