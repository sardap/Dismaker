#pragma once
#ifndef CONDITIONAL_PROCUDE_EFFECT_H

	#define CONDITIONAL_PROCUDE_EFFECT_H
	#include "ProcedeEffect.h"	
	
	class DialogTree;
	class Feeling;

	class ConditionalPrcoudeEffect : public ProcedeEffect
	{
		public:
			ConditionalPrcoudeEffect(World& _world, const char* id, Feeling* feeling, int target);
			~ConditionalPrcoudeEffect();

			void Excute() override;

		private:
			Feeling* _feeling;
			int _target;
	};

#endif // !CONDITIONAL_PROCUDE_EFFECT_H
