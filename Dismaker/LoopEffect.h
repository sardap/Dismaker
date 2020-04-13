#pragma once
#ifndef EFFECT_BARE_BONES_H
	
	#define EFFECT_BARE_BONES_H
	#include "Effect.h"

	class LoopEffect : public Effect
	{
		public:
			LoopEffect(World& world);
			~LoopEffect();
			void Excute() override;
	};

#endif // !1
