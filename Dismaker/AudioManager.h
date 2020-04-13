#pragma once
#ifndef AUDIO_MANAGER_H

	#define AUDIO_MANAGER_H
	#include <string>
	#include <vector>
	#include <SFML\Audio.hpp>
	#include <map>
	#include <tuple>

	class AudioManager
	{
		public:
			AudioManager();
			~AudioManager();

			void AddMusicTrack(std::string id, std::string fileLocation);

			void PlayMusic(const std::string& id, bool loop = false);
			void StartMusic();
			void StopMusic();

			void PlayDialog(const std::string& fileLocation);

			void PlaySFXSound(const std::string& fileLocation);

		private:
			std::pair<std::string, sf::Music> _musicPlaying;
			sf::Music _dialogPlaying;
			std::vector<sf::Sound> _soundsPlaying;

			std::map<std::string, std::string> _musicTracks;

	};	

#endif // !AUDIO_MANAGER

