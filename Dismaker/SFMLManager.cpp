#include "SFMLManager.h"
#include "Configuration.h"
#include "AudioManager.h"

bool SFMLManager::_singletonCreated = false;

SFMLManager* SFMLManager::_singleton = nullptr;

SFMLManager* SFMLManager::GetInstane()
{
	if(_singleton == nullptr)
	{
		_singleton = new SFMLManager();
	}

	return _singleton;
}

SFMLManager::SFMLManager()
{
	if(!_singletonCreated)
	{
		_singleton = this;
		_singletonCreated = true;
	}
	else
	{
		throw "SIGNLTION CRETED ALLREAY FUCKTARD"; // Wicked spelling
	}

	_window = new sf::RenderWindow
	(
		sf::VideoMode
		(
			static_cast<unsigned int>(Configuration::GetInstane()->GetWindowRectangle().width),
			static_cast<unsigned int>(Configuration::GetInstane()->GetWindowRectangle().height)
		),
		Configuration::GetInstane()->GetWindowText()
	);
}

SFMLManager::~SFMLManager()
{
	delete _window;
}

sf::RenderWindow* SFMLManager::GetRenderWindow()
{
	return _window;
}

sf::Window* SFMLManager::GetWindow()
{
	return _window;
}

AudioManager& SFMLManager::GetAudioManager()
{
	return _audioManager;
}

sf::Event& SFMLManager::GetEvent()
{
	int x = 0;
	return _event;
}

void SFMLManager::ProcessEvents()
{
	GetWindow()->pollEvent(_event);
}