#include "GUIManager.h"
#include "Renderable.h"
#include <SharedLibary\PaulTils.h>
#include "IProcessInput.h"
#include "OptionButton.h"
#include "Option.h"
#include "DialogTextBox.h"
#include "GameUtils.h"
#include "DialogHolder.h"
#include "DialogTree.h"
#include "World.h"
#include "GameShape.h"
#include "Configuration.h"
#include "SFMLManager.h"

GUIManager::GUIManager(World& world, GameState::Value& gameState) : _world(world), _gameState(gameState)
{
	sf::RectangleShape dialogTextBoxRectangle;
	dialogTextBoxRectangle.setSize(sf::Vector2f(GameUtils::GetScreenWidth() * 0.80, GameUtils::GetScreenHieght() * 0.4));
	dialogTextBoxRectangle.setPosition
	(
		sf::Vector2f
		(
			(GameUtils::GetScreenWidth() - dialogTextBoxRectangle.getSize().x) / 2,
			GameUtils::GetScreenHieght() - dialogTextBoxRectangle.getSize().y - GameUtils::GetScreenHieght() * 0.03
		)
	);

	_guiElements.push_back(new DialogTextBox(*_world.GetHolder("marx")->GetActiveTree()->GetActiveNode(), dialogTextBoxRectangle, GameState::Game));


	// Menu Items
	sf::RectangleShape* menuBackground = new sf::RectangleShape();
	menuBackground->setSize(sf::Vector2f(SFMLManager::GetInstane()->GetRenderWindow()->getSize()));

	GameShape* gameShape = new GameShape
	(
		menuBackground,
		Configuration::GetInstane()->GetMenuConfigInfo().textureLocationMap,
		Configuration::GetInstane()->GetMenuConfigInfo().entranceID,
		GameState::Menu
	);

	_guiElements.push_back(gameShape);

}

GUIManager::~GUIManager()
{
	PaulTils::DeleteClear(_guiElements);
}

void GUIManager::Update(const sf::Time& deltaTime)
{
	if(PaulTils::HasInsatnce<DialogTextBox*>(_guiElements))
	{
		PaulTils::Find<DialogTextBox*>(_guiElements)->SetDialog(*_world.GetHolder("marx")->GetActiveTree()->GetActiveNode());
	}
}

void GUIManager::Render(RenderBridge& renderer, GameState::Value gameState)
{
	for each (Renderable* i in _guiElements)
	{
		i->Render(&renderer, gameState);
	}
}

void GUIManager::ProcessInput(const InputBridge& inputBridge)
{
	std::vector<IProcessInput*> processInput;

	for each (Renderable* i in _guiElements)
	{
		if(PaulTils::IsInstance<IProcessInput*>(i))
		{
			processInput.push_back(dynamic_cast<IProcessInput*>(i));
		}
	}

	for each (IProcessInput* i in processInput)
	{
		i->ProcessInput(inputBridge);
	}

	UniversalInputs(inputBridge);
}

void GUIManager::UniversalInputs(const InputBridge& inputBridge)
{
	if(inputBridge.InputPressed(Input::Escape))
	{
		_gameState == GameState::Game ? _gameState = GameState::Menu : _gameState = GameState::Game;
	}
}