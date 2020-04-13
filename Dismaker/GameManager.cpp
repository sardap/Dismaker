#include "GameManger.h"
#include "Configuration.h"
#include "BridgerManager.h"
#include "Bridges.h"
#include "DialogHolder.h"
#include "Effects.h"
#include "World.h"
#include "OptionButton.h"
#include "ColorUtils.h"
#include "DialogHolder.h"
#include "Dialog.h"
#include "DialogTree.h"
#include "World.h"
#include "DialogTextBox.h"
#include "GameUtils.h"
#include "GUIManager.h"
#include "KeyBoardInputBridge.h"
#include "SFMLManager.h"
#include "GameClock.h"

GameManager::GameManager()
{
	BridgeManager* bridgeManager = new BridgeManager();

	_gameState = GameState::Game;

	_config = new Configuration();
	_mouseInfo = new MouseInfo();
	_bridgeManager = bridgeManager;
	_exit = false;

	_player = new Player();
	_world = new World();
	_gameClock = new GameClock();

	_guiManager = new GUIManager(*_world, _gameState);

	bridgeManager->AddBridge(new RenderBridge());
	bridgeManager->AddBridge(new KeyboardInputBridge());
}

GameManager::~GameManager()
{
	delete _world;
	delete _player;
	delete _config;
	delete _bridgeManager;
	delete _guiManager;
	delete _gameClock;
}

void GameManager::Start()
{
	_player->RenderGreeting(_bridgeManager->GetBridge<RenderBridge*>());

	while(!_exit)
	{
		GameLoop();
	}
}

void GameManager::GameLoop()
{
	_gameClock->LoopStart();
	
	SFMLManager::GetInstane()->ProcessEvents();
	
	_guiManager->Update(_gameClock->GetDeltaTime());
	_bridgeManager->GetBridge<InputBridge*>()->Update(_gameClock->GetDeltaTime());

	Render();
	ProcessInput();
}

void GameManager::ProcessInput()
{
	_mouseInfo->Update(_gameClock->GetDeltaTime());

	_guiManager->ProcessInput(*_bridgeManager->GetBridge<InputBridge*>());

	CheckExitRequested();
}

void GameManager::CheckExitRequested()
{
	//_exit = SFMLManager::GetInstane()->GetEvent().type == sf::Event::Closed;
}

void GameManager::Render()
{
	RenderBridge* renderer = _bridgeManager->GetBridge<RenderBridge*>();

	renderer->Clear();

	_world->Render(renderer, _gameState);

	_guiManager->Render(*renderer, _gameState);
	 
	renderer->Display();
}