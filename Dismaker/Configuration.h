#pragma once	
#ifndef CONFIGURATION_H

	#define CONFIGURATION_H
	#include <string>	
	#include <SFML\Graphics\Rect.hpp>
	#include <SFML\Graphics.hpp>
	#include <pugiXML\pugixml.hpp>
	#include "TextBoxConfigInfo.h"
	#include "AudioConfigInfo.h"
	#include "GameShapeConfigInfo.h"

	class Configuration
	{
		// STATIC SECTION
		public:
			static Configuration* GetInstane();

		private:
			static bool _singletonCreated;
			static Configuration* _singleton;

		// END OF STATIC SECTION
				
		public:
			Configuration(const char* fileName = "Resources\\ConfigFile.xml");
			~Configuration();

			std::string GetPlayerName();
			sf::IntRect GetWindowRectangle();
			std::string GetWindowText();
			TextBoxConfigInfo GetOptionButtonConfigInfo();
			TextBoxConfigInfo GetDialogTextBoxConnfigInfo();
			int GetClickWindow();
			const AudioConfigInfo& GetAudioConfigInfo();
			GameShapeConfigInfo GetMenuConfigInfo();

		private:
			std::string _playerName;
			sf::IntRect _windowRectangle;
			std::string _windowText;
			TextBoxConfigInfo _optionTextConfigInfo;
			TextBoxConfigInfo _dialogTextBoxConnfigInfo;
			int _clickWindow;
			AudioConfigInfo _audioConfigInfo;
			GameShapeConfigInfo _menuConfigInfo;

			sf::Color BuildColorFromNode(const pugi::xml_node& node);
			TextConfigInfo BuildTextConfigInfo(const pugi::xml_node& node);
			BorderConfigInfo BuildBorderConfigInfo(const pugi::xml_node& node);
			RectangleConfigInfo BuildRecntalgeConfigInfo(const pugi::xml_node& node);
			TextBoxConfigInfo BuildTextBoxConfigInfo(const pugi::xml_node& node);
			
			AudioConfigInfo BuildAudioConfigInfo(const pugi::xml_node& node);
			GameShapeConfigInfo BuildGameShapeConfigInfo(const pugi::xml_node& node);

			void LoadMusic(const pugi::xml_node& node);

			void LoadFile(const char* fileName);
	};

#endif // !SETTINGS_H
