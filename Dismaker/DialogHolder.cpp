#include "DialogHolder.h"
#include "DialogTree.h"
#include "Dialog.h"
#include "Feeling.h"
#include "RenderBridge.h"
#include <SharedLibary\PaulTils.h>
#include "GameShape.h"

DialogHolder::DialogHolder(std::string name, std::string description, Feeling feeling, DialogTreeMap dialogTreeMap, std::string activeTreeID, GameShape* portrait, GameShape* backGround) : Renderable(GameState::Game)
{
	_name = name;
	_description = description;
	_feeling = feeling;
	_dialogTreeMap = dialogTreeMap;
	_activeTreeID = activeTreeID;
	_portrait = portrait;
	_backGround = backGround;
}

DialogHolder::~DialogHolder()
{
	PaulTils::DeleteClear(_dialogTreeMap);
	delete _portrait;
	delete _backGround;
}

void DialogHolder::ProcessInput(const char* input)
{
	_dialogTreeMap[_activeTreeID]->ProcessInput(input);
}

bool DialogHolder::AreYou(std::string name)
{
	return PaulTils::CaseInsensitiveStringCompare(name, _name);
}

void DialogHolder::SetPortrait(const std::string& portraitID)
{
	_portrait->LoadTexture(portraitID);
}

DialogTree* DialogHolder::GetActiveTree()
{
	return _dialogTreeMap[_activeTreeID];
}

void  DialogHolder::SetActiveDialogTree(const char* dialogTreeID)
{
	_dialogTreeMap[_activeTreeID] = _dialogTreeMap[dialogTreeID];
}

Feeling* DialogHolder::GetFeeling()
{
	return &_feeling;
}

void DialogHolder::InternalRender(RenderBridge* renderer, GameState::Value gameState)
{
	_backGround->Render(renderer, gameState);
	_portrait->Render(renderer, gameState);
}



