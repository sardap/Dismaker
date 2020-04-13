#pragma once
#ifndef OPTION_H

	#define OPTION_H
	#include <string>
	#include "Effect.h"

	class Option
	{
		public:
			// Efect must be a pointer becuase it's an abstract class
			Option(const char* text, Effect* Effect);
			~Option();

			void Select();
			std::string GetText() const;

		private:
			std::string _text;
			Effect* _effect;
	};

#endif // !OPTION_H

