#include "Renderable.h"

Renderable::Renderable(GameState::Value gameState)
{
	_gameState = gameState;
}

Renderable::~Renderable()
{
}

void Renderable::Render(RenderBridge* renderer, GameState::Value gameState)
{
	if(_gameState == gameState)
	{
		InternalRender(renderer, gameState);
	}
}

GameState::Value Renderable::GetGameState()
{
	return _gameState;
}
