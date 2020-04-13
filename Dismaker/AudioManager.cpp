#include "AudioManager.h"
#include "GameExpections.h"
#include <SharedLibary\PaulTils.h>
#include "Configuration.h"

#define DIALOG_VOLUME Configuration::GetInstane()->GetAudioConfigInfo().dialogVolume
#define MUSIC_VOLUME Configuration::GetInstane()->GetAudioConfigInfo().musicVolume
#define SFX_VOLUME Configuration::GetInstane()->GetAudioConfigInfo().sfxVolume

AudioManager::AudioManager()
{
	_musicPlaying.first = "";
	_musicPlaying.second.setVolume(MUSIC_VOLUME);
}

AudioManager::~AudioManager()
{
}

void AudioManager::AddMusicTrack(std::string id, std::string fileLocation)
{
	if(PaulTils::FileExists(fileLocation) && fileLocation.find(".ogg") != -1)
	{
		_musicTracks[id] = fileLocation;
	}
	else
	{
		throw UNABLE_TO_LOAD_FILE;
	}
}

void AudioManager::PlayMusic(const std::string& id, bool loop)
{
	if(id != _musicPlaying.first)
	{
		_musicPlaying.first = id;

		_musicPlaying.second.openFromFile(_musicTracks[ id ]);
		_musicPlaying.second.setLoop(loop);

		_musicPlaying.second.play();
	}
}

void AudioManager::StartMusic()
{
	_musicPlaying.second.play();
}

void AudioManager::StopMusic()
{
	_musicPlaying.second.stop();
}

void AudioManager::PlayDialog(const std::string& fileLocation)
{
	_dialogPlaying.setVolume(DIALOG_VOLUME);
	_dialogPlaying.openFromFile(fileLocation);

	_dialogPlaying.play();
}

void AudioManager::PlaySFXSound(const std::string& fileLocation)
{
	sf::SoundBuffer soundBuffer;

	if(soundBuffer.loadFromFile(fileLocation))
	{
		throw UNABLE_TO_LOAD_FILE;
	}

	sf::Sound newSound;
	newSound.setBuffer(soundBuffer);

	_soundsPlaying.push_back(newSound);
	_soundsPlaying.back().setVolume(SFX_VOLUME);

	_soundsPlaying.back().play();
}
