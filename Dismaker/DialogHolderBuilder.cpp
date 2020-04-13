#include "DialogHolderBuilder.h"
#include <SharedLibary\PaulTils.h>
#include "DialogTreeBuilder.h"
#include "OptionBuilder.h"
#include "DialogTree.h"
#include "Dialog.h"
#include "Effects.h"
#include "Feeling.h"
#include "World.h"
#include "GameUtils.h"
#include "GameShape.h"
#include <map>
#include "GameState.h"

DialogHolderBuilder::DialogHolderBuilder()
{
}

DialogHolderBuilder::~DialogHolderBuilder()
{
}

void DialogHolderBuilder::SetFileName(const char* fileName)
{
	_fileName = fileName;
}

void DialogHolderBuilder::SetWorld(World* world)
{
	_world = world;
}

void DialogHolderBuilder::AddDialogTree(const char* id, DialogTree* tree)
{
	_dialogTreeMap.insert(std::pair<const char*, DialogTree*>(id, tree));
}


void DialogHolderBuilder::CreateDirevred(void** objPtr)
{
	*objPtr = CreateDialogHolderFromFile();
}

Effect* DialogHolderBuilder::CreateEffectFromXMLNode(pugi::xml_node effectNode)
{
	std::string type = effectNode.attribute("type").value();

	if(type == "Procede")
	{
		return new ProcedeEffect(*_world, _id, effectNode.attribute("target").value());
	}
	else if(type == "Exit")
	{
		return new ExitEffect(*_world);
	}
	else if(type == "Loop")
	{
		return new LoopEffect(*_world);
	}
	else if(type == "ChangeFeeling")
	{
		return new ChangeFeelingEffect
		(
			*_world,
			_id,
			effectNode.attribute("target").value(),
			PaulTils::StringToInt(effectNode.attribute("value").value())
		);
	}
	else if(type == "MusicEffect")
	{
		return new PlayMusicEffect
		(
			*_world,
			effectNode.attribute("id").value(),
			effectNode.attribute("loop").as_bool()
		);
	}
	else if(type == "ChangePortrait")
	{
		return new ChangePortiratEffect
		(
			*_world,
			_id,
			effectNode.attribute("target").value()
		);
	}

	return NULL;
}

Dialog* DialogHolderBuilder::CreateDialogFromXMLNode(pugi::xml_node dialogNode)
{
	Dialog* newDialog = new Dialog(dialogNode.attribute("text").value(), dialogNode.child("Audio").attribute("fileLocation").value());

	for each (pugi::xml_node optionNode in dialogNode.children("Option"))
	{
		OptionBuilder* optionBuilder = new OptionBuilder();

		optionBuilder->SetWorld(_world);

		optionBuilder->AddText(optionNode.attribute("text").value());

		for each (pugi::xml_node effectNode in optionNode.children("Effect"))
		{
			optionBuilder->AddEffect(CreateEffectFromXMLNode(effectNode));
		}

		newDialog->AddOption((Option*)optionBuilder->Create());

		delete optionBuilder;
	}

	return newDialog;
}

void DialogHolderBuilder::AddDialogTreeToMap(pugi::xml_node dialogTreeNode)
{
	DialogTreeBuilder dialogTreeBuilder;

	for each (pugi::xml_node dialogNode in dialogTreeNode.children("Dialog"))
	{
		dialogTreeBuilder.AddDialog
		(
			dialogNode.attribute("id").value(),
			CreateDialogFromXMLNode(dialogNode)
		);
	}

	dialogTreeBuilder.SetEntrance(dialogTreeNode.attribute("entrance").value());

	AddDialogTree(dialogTreeNode.attribute("id").value(), (DialogTree*)dialogTreeBuilder.Create());
}

Feeling DialogHolderBuilder::CreateFeelingForHolder()
{
	Feeling newFeeling;

	for each (pugi::xml_node feelingNode in _profileNode.children("Feeling"))
	{
		newFeeling.AddFeeling
		(
			feelingNode.attribute("id").value(),
			PaulTils::StringToInt(feelingNode.attribute("value").value())
		);
	}

	return newFeeling;
}

std::map<std::string, std::string> DialogHolderBuilder::CreateTextureLocationMapFromNode(const pugi::xml_node& texturesNode)
{
	TextureLocationMap result;

	for each (auto textureNode in texturesNode.children("Texture"))
	{
		result[textureNode.attribute("id").value()] = textureNode.attribute("fileLocation").value();
	}

	return result;
}

// @Bad Combied these two functions maybe just pass node + pos and size
GameShape* DialogHolderBuilder::CreateBackground(const pugi::xml_node& texturesNode)
{
	sf::RectangleShape* rectangle = new sf::RectangleShape();

	rectangle->setPosition(0, 0);
	rectangle->setSize(sf::Vector2f
	(
		GameUtils::GetScreenWidth(),
		GameUtils::GetScreenHieght()
	));

	return new GameShape(rectangle, CreateTextureLocationMapFromNode(texturesNode), texturesNode.attribute("startId").value(), GameState::Game);
}


GameShape* DialogHolderBuilder::CreatePortrait(const pugi::xml_node& texturesNode)
{
	sf::RectangleShape* rectangle = new sf::RectangleShape();

	rectangle->setSize(sf::Vector2f(GameUtils::GetScreenWidth() * 0.289, GameUtils::GetScreenHieght() * 0.85));
	rectangle->setPosition(GameUtils::GetScreenWidth() * 0.7 - rectangle->getSize().x / 2, GameUtils::GetScreenHieght() - rectangle->getSize().y);
	
	return new GameShape(rectangle, CreateTextureLocationMapFromNode(texturesNode), texturesNode.attribute("startId").value(), GameState::Game);
}


DialogHolder* DialogHolderBuilder::CreateDialogHolderFromFile()
{
	pugi::xml_document profileDoc;

	pugi::xml_parse_result result = profileDoc.load_file(_fileName.c_str());

	_profileNode = profileDoc.child("root").child("DialogHolder");

	_id = _profileNode.attribute("name").value();

	std::string entranceID = "";

	for each (auto profileDialogTreeNode in _profileNode.children("DialogTree"))
	{
		pugi::xml_document dialogTreeFile;

		pugi::xml_parse_result result = dialogTreeFile.load_file(profileDialogTreeNode.attribute("fileName").value());

		for each (pugi::xml_node dialogTreeNode in dialogTreeFile.child("root").children("DialogTree"))
		{
			AddDialogTreeToMap(dialogTreeNode);

			if(dialogTreeFile.attribute("entrace").value() == "True")
			{
				entranceID = dialogTreeFile.attribute("entrace").value();
			}
		}
	}

	if(entranceID == "")
	{
		entranceID = _dialogTreeMap.begin()->first;
	}

	return new DialogHolder
	(
		_id,
		_profileNode.attribute("description").value(),
		CreateFeelingForHolder(),
		_dialogTreeMap,
		entranceID,
		CreatePortrait(_profileNode.child("Portrait")),
		CreateBackground(_profileNode.child("Background"))
	);
}

