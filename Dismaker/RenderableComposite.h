#pragma once
#ifndef RENDERABLE_COMPOSITE_H

	#define RENDERABLE_COMPOSITE_H
	#include <vector>
	#include "Renderable.h"

	class RenderableComposite : public Renderable
	{
		public:
			RenderableComposite(GameState::Value gamestate);
			~RenderableComposite();

			void AddBack(Renderable* renderable);
			void AddFront(Renderable* renderable);

		protected:
			void InternalRender(RenderBridge* renderer, GameState::Value gameState) override;

		private:
			std::vector<Renderable*> _rendableElements;
	};

#endif // !RENDERABLE_COMPOSITE_H

