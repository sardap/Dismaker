#pragma once
#ifndef MOUSE_INFO_H

	#define MOUSE_INFO_H
	#include <map>
	#include <SFML\Graphics.hpp>

	class MouseInfo
	{
		// STATIC SECTION
		public:
			static MouseInfo& GetInstane();

		private:
			static bool _singletonCreated;
			static MouseInfo* _dialogTree;

		// END OF STATIC SECTION

		public:
			MouseInfo();
			~MouseInfo();

			void Update(const sf::Time& deltaTime);

			bool ButtonClicked(sf::Mouse::Button button);
			bool ShapeClicked(const sf::Shape& shape, sf::Mouse::Button button);

		private:
			std::map<sf::Mouse::Button, int64_t> _clickState;
			int _clickWindow;
			sf::Time _lastUpdateTime;

			sf::Vector2f GetMousePostion();

	};

#endif // !MOUSE_INFO_H
