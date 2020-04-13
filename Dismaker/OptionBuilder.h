#pragma once
#ifndef OPTION_BUILDER_H

	#define OPTION_BUILDER_H
	#include <vector>
	#include "Builder.h"
	#include "pugixml/pugixml.hpp"

	class Effect;
	class World;
	
	class OptionBuilder : public Builder
	{
		public:
			OptionBuilder();
			~OptionBuilder();

			void AddEffect(Effect* toAdd);
			void AddText(const char* text);
			void SetWorld(World* world);

		protected:
			void CreateDirevred(void** objPtr);

		private:
			World* _world;
			std::string _text;
			std::vector<Effect*> _effects;
	};

#endif // !OPTION_BUILDER_H