#pragma once
#ifndef CHANGE_PORTIRAT_EFFECT_H

	#define CHANGE_PORTIRAT_EFFECT_H
	#include "Effect.h"

	class ChangePortiratEffect : public Effect
	{
		public:
			ChangePortiratEffect(World& world, std::string holderID, std::string portraitID);
			~ChangePortiratEffect();

			void Excute() override;

		private:
			std::string _holderID;
			std::string _portraitID;
	};

#endif // !CHANGE_PORTIRAT_H
