#include "World.h"
#include "RenderBridge.h"
#include "DialogHolder.h"
#include "DialogHolderBuilder.h"
#include "GameExpections.h"
#include "Renderable.h"

World::World(const char* dialogHoldersInfoFileName)
{
	_activeHolder = NULL;
	PopulateDialogHolders(dialogHoldersInfoFileName);

}

World::World() : World(CHARATERS_FILENAME)
{
}

World::~World()
{
	for(size_t i = 0; i < _holders.size(); i++)
	{
		delete _holders[i];
	}

	_holders.clear();
}

void World::Render(RenderBridge* renderer, GameState::Value gameState)
{
	_activeHolder->Render(renderer, gameState);
}

void World::AddHolder(DialogHolder* holder)
{
	_holders.push_back(holder);

	if(_holders.size() == 1)
	{
		_activeHolder = _holders[0];
	}
}

DialogHolder* World::GetHolder(std::string name)
{
	for each (DialogHolder* i in _holders)
	{
		if(i->AreYou(name))
		{
			return i;
		}
	}

	throw DIALOG_HOLDER_NOT_FOUND;
}

void World::SetActiveHolder(std::string name)
{
	_activeHolder = GetHolder(name);
}


void World::PopulateDialogHolders(const char* fileName)
{
	pugi::xml_document charaterDoc;

	pugi::xml_parse_result result = charaterDoc.load_file(fileName);

	DialogHolderBuilder dialogHolderBuilder;

	dialogHolderBuilder.SetWorld(this);

	for each (auto charaterNode in charaterDoc.child("root").children("Charater"))
	{
		dialogHolderBuilder.SetFileName(charaterNode.attribute("fileName").value());

		AddHolder((DialogHolder*) dialogHolderBuilder.Create());
	}
}