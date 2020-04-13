#pragma once
#ifndef EFFECT_H
	
	#define EFFECT_H
	#include <vector>

	class World;
	
	class Effect // Abstract
	{
		public:
			Effect(World& world);
			virtual ~Effect();

			virtual void Excute() = 0;

		private:
			World& _world;


		protected:
			World& GetWorld();
	};

#endif // !EFFECT_H
