#pragma once
#ifndef EXIT_EFFECT_H

	#define EXIT_EFFECT_H
	#include "Effect.h"	

	class ExitEffect : public Effect
	{
		public:
			ExitEffect(World& world);
			~ExitEffect();
			void Excute() override;
	};

#endif // !EXIT_EFFECT_H
