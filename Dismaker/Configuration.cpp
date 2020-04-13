#include "Configuration.h"
#include <pugixml/pugixml.hpp>
#include <iostream>
#include <SharedLibary\PaulTils.h>
#include "GameUtils.h"
#include "SFMLManager.h"
#include "AudioManager.h"

bool Configuration::_singletonCreated = false;

Configuration* Configuration::_singleton = nullptr;

Configuration* Configuration::GetInstane()
{
	return _singleton;
}

Configuration::Configuration(const char* fileName)
{
	if(_singletonCreated)
	{
		throw "Singleton Already Created Expection";
	}

	_singletonCreated = true;
	_singleton = this;

	LoadFile(fileName);
}

Configuration::~Configuration()
{
}

std::string Configuration::GetPlayerName()
{
	return _playerName;
}

sf::IntRect Configuration::GetWindowRectangle()
{
	return _windowRectangle;
}

std::string Configuration::GetWindowText()
{
	return _windowText;
}

TextBoxConfigInfo Configuration::GetOptionButtonConfigInfo()
{
	return _optionTextConfigInfo;
}

TextBoxConfigInfo Configuration::GetDialogTextBoxConnfigInfo()
{
	return _dialogTextBoxConnfigInfo;
}

int Configuration::GetClickWindow()
{
	return _clickWindow;
}

const AudioConfigInfo& Configuration::GetAudioConfigInfo()
{
	return _audioConfigInfo;
}

GameShapeConfigInfo Configuration::GetMenuConfigInfo()
{
	return _menuConfigInfo;
}

sf::Color Configuration::BuildColorFromNode(const pugi::xml_node& node)
{
	sf::Color result;

	result = GameUtils::StringToColor(node.attribute("color").value());

	if(node.attribute("alpha").as_double() > 0)
	{
		result.a = (sf::Uint8)(255 * node.attribute("alpha").as_double());
	}

	return result;
}

TextConfigInfo Configuration::BuildTextConfigInfo(const pugi::xml_node& node)
{
	TextConfigInfo result;

	result.font = GameUtils::BuildFont(node.attribute("fontLocation").value());
	result.textColor = BuildColorFromNode(node);
	result.size = PaulTils::StringToInt(node.attribute("size").value());
	result._buffer = PaulTils::StringToFloat(node.attribute("buffer").value());

	return result;
}

BorderConfigInfo Configuration::BuildBorderConfigInfo(const pugi::xml_node& node)
{
	BorderConfigInfo result;

	result.fillColor = BuildColorFromNode(node);
	result.borderFatness = PaulTils::StringToInt(node.attribute("borderFatness").value());

	return result;
}

RectangleConfigInfo Configuration::BuildRecntalgeConfigInfo(const pugi::xml_node& node)
{
	RectangleConfigInfo result;

	result.fillColor = BuildColorFromNode(node);

	return result;
}

TextBoxConfigInfo Configuration::BuildTextBoxConfigInfo(const pugi::xml_node& node)
{
	TextBoxConfigInfo result;

	result.textInfo = BuildTextConfigInfo(node.child("TextInfo"));
	result.borderInfo = BuildBorderConfigInfo(node.child("BorderInfo"));
	result.rectangleInfo = BuildRecntalgeConfigInfo(node.child("RectangleInfo"));

	return result;
}

AudioConfigInfo Configuration::BuildAudioConfigInfo(const pugi::xml_node& node)
{
	AudioConfigInfo result;

	result.dialogVolume = node.child("Dialog").attribute("level").as_float();
	result.musicVolume = node.child("Music").attribute("level").as_float();
	result.sfxVolume = node.child("SFX").attribute("level").as_float();

	return result;
}

GameShapeConfigInfo Configuration::BuildGameShapeConfigInfo(const pugi::xml_node& node)
{
	GameShapeConfigInfo result;

	result.entranceID = node.attribute("entrance").value();
	
	for each (auto texture in node.children("Texture"))
	{
		result.textureLocationMap[texture.attribute("id").value()] = texture.attribute("fileLocation").value();
	}

	return result;
}

void Configuration::LoadMusic(const pugi::xml_node& node)
{
	for each (auto trackNode in node.children("Track"))
	{
		SFMLManager::GetInstane()->GetAudioManager().AddMusicTrack
		(
			trackNode.attribute("id").value(), 
			trackNode.attribute("fileLocation").value()
		);
	}
}

void Configuration::LoadFile(const char* fileName)
{
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file(fileName);

	pugi::xml_node rootNode = doc.child("root");

	_playerName = rootNode.child("Player").attribute("name").value();

	double shitme = PaulTils::StringToDouble(rootNode.child("Window").attribute("width").value());

	_windowRectangle = sf::IntRect
	(
		PaulTils::StringToDouble(rootNode.child("Window").attribute("x").value()),
		PaulTils::StringToDouble(rootNode.child("Window").attribute("y").value()),
		PaulTils::StringToDouble(rootNode.child("Window").attribute("width").value()),
		PaulTils::StringToDouble(rootNode.child("Window").attribute("height").value())
	);

	_windowText = rootNode.child("Window").attribute("text").value();

	_optionTextConfigInfo = BuildTextBoxConfigInfo(rootNode.child("OptionButtonInfo"));
	_dialogTextBoxConnfigInfo = BuildTextBoxConfigInfo(rootNode.child("DialogTextInfo"));

	_clickWindow = rootNode.child("Mouse").attribute("clickWindow").as_int();

	_audioConfigInfo = BuildAudioConfigInfo(rootNode.child("Audio"));

	LoadMusic(rootNode.child("Music"));

	_menuConfigInfo = BuildGameShapeConfigInfo(rootNode.child("Menu").child("GameShape"));
}