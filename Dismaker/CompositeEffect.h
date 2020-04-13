#pragma once
#ifndef COMPOSITE_EFFECT_H

	#define COMPOSITE_EFFECT_H
	#include <vector>
	#include "Effect.h"
	
	class CompositeEffect : public Effect
	{
		public:
			CompositeEffect(World& world, std::vector<Effect*> toAdd);
			~CompositeEffect ();

			void Excute() override;

		private:
			std::vector<Effect*> _elements;

			void AddEffect(std::vector<Effect*> toAdd);
	};


#endif // !COMPOSITE_EFFECT_H
