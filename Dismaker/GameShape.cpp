#include "GameShape.h"
#include <SFML\Graphics.hpp>
#include <SharedLibary\PaulTils.h>
#include "RenderBridge.h"
#include "GameExpections.h"

GameShape::GameShape(sf::Shape* shape, TextureLocationMap textureMap, const std::string& activeID, GameState::Value gameState) : Renderable(gameState)
{
	_shape = shape;
	_textureMap = textureMap;

	LoadTexture(activeID);
}

GameShape::~GameShape()
{
	delete _shape;
	delete _loadedTexture;
	PaulTils::DeleteClear(_textureMap);
}

void GameShape::LoadTexture(const std::string& id)
{
	if(_textureMap.find(id) == _textureMap.end())
	{
		throw INVALID_KEY_IN_MAP;
	}

	delete _loadedTexture;

	_loadedTexture = new sf::Texture();

	if(!_loadedTexture->loadFromFile(_textureMap[id]))
	{
		throw UNABLE_TO_LOAD_FILE;
	}

	_loadedTexture->setSmooth(true);

	_loadedTexture->setRepeated(false);

	_shape->setTexture(_loadedTexture);
}

void GameShape::InternalRender(RenderBridge* renderer, GameState::Value gameState)
{
	renderer->Render(*_shape);
}