#pragma once
#ifndef CHANGE_FEELING_EFFECT_H

	#define CHANGE_FEELING_EFFECT_H
	#include <string>	
	#include "Effect.h"

	class DialogHolder;	

	class ChangeFeelingEffect : public Effect
	{
		public:
			ChangeFeelingEffect(World& world, const std::string& dialogHolderId, const std::string& feelingName, int value);
			~ChangeFeelingEffect();

			void Excute() override;

		private:
			std::string _holder;
			std::string _feelingName;
			int _value;

	};

#endif // !CHANGE_FEELING_EFFECT_H
