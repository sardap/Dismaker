#pragma once
#ifndef PROCEDE_EFFECT_H
	
	#define PROCEDE_EFFECT_H
	#include <string>
	#include "Effect.h"

	class DialogTree;
	class Dialog;

	class ProcedeEffect : public Effect
	{
		public:
			ProcedeEffect(World& world, std::string ownerID, const char* targetID);
			~ProcedeEffect();
			void Excute();

		private:
			std::string _ownerID;
			std::string _connectionID;

	};

#endif // PROCEDE_EFFECT_H!
