#include "Option.h"

Option::Option(const char* text, Effect* Effect)
{
	_text = text;
	_effect = Effect;
}

Option::~Option()
{
	delete _effect;
}

void Option::Select()
{
	_effect->Excute();
}

std::string Option::GetText() const
{
	return _text;
}