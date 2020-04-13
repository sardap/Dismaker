#pragma once
#ifndef GAME_SHAPE_H

	#define GAME_SHAPE_H
	#include "Renderable.h"
	#include "GameShapeConfigInfo.h"

	namespace sf
	{
		class Shape;
	}

	class GameShape : public Renderable
	{	
		public:
			GameShape(sf::Shape* shape, TextureLocationMap textureMap, const std::string& activeID, GameState::Value gameState);
			~GameShape();

			void LoadTexture(const std::string& id);

		protected:
			void InternalRender(RenderBridge* renderer, GameState::Value gameState) override;


		private:
			TextureLocationMap _textureMap;
			sf::Texture* _loadedTexture;
			sf::Shape* _shape;
	};

#endif // !GAME_SHAPE_H
