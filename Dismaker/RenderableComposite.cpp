#include "RenderableComposite.h"
#include <SharedLibary\PaulTils.h>

RenderableComposite::RenderableComposite(GameState::Value gamestate) : Renderable(gamestate)
{
}

RenderableComposite::~RenderableComposite()
{
	PaulTils::DeleteClear(_rendableElements);
}

void RenderableComposite::AddBack(Renderable* renderable)
{
	_rendableElements.push_back(renderable);
}

void RenderableComposite::AddFront(Renderable* renderable)
{
	_rendableElements.insert(_rendableElements.begin(), renderable);
}

void RenderableComposite::InternalRender(RenderBridge* renderer, GameState::Value gameState)
{
	for each (Renderable* renderable in _rendableElements)
	{
		renderable->Render(renderer, gameState);
	}
}
