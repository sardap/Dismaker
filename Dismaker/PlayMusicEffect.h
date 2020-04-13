#pragma once
#ifndef PLAY_MUSIC_EFFECT_H

	#define PLAY_MUSIC_EFFECT_H
	#include"Effect.h"	

	class PlayMusicEffect : public Effect
	{
		public:
			PlayMusicEffect(World& world, std::string id, bool loop);
			~PlayMusicEffect();

			void Excute() override;

		private:
			std::string _id;
			bool _loop;

	};

#endif // !PLAY_MUSIC_EFFECT_H
