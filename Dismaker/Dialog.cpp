#include "Dialog.h"
#include <SharedLibary\PaulTils.h>
#include "Option.h"
#include "SFMLManager.h"
#include "AudioManager.h"

Dialog::Dialog(std::string text, std::vector<Option*> options, std::string fileLocation)
{
	_options = options;
	_text = text;
	_fileLocation = fileLocation;
}

Dialog::Dialog(std::string text, Option* option, std::string fileLocation) : Dialog(text, std::vector<Option*> {option}, fileLocation)
{
}

Dialog::Dialog(std::string text, std::string fileLocation) : Dialog(text, std::vector<Option*>(), fileLocation)
{
}

Dialog::Dialog() : Dialog("")
{

}

Dialog::~Dialog()
{
	PaulTils::DeleteClear(_options);
}

std::string Dialog::GetText() const
{
	return _text;
}

std::vector<Option*> Dialog::GetOptions()
{
	return _options;
}

void Dialog::AddOption(Option* option)
{
	_options.push_back(option);
}

void Dialog::PlayAudio()
{
	// @Bad need more for this maybe pass in a class or somthing i don't know
	if(_fileLocation != "")
	{
		SFMLManager::GetInstane()->GetAudioManager().PlayDialog(_fileLocation);
	}
}

void Dialog::ProcessInput(const char* input)
{
	for each (Option* i in _options)
	{
		if(PaulTils::CaseInsensitiveStringCompare(i->GetText().c_str(), input))
		{
			i->Select();
		}
	}
}
