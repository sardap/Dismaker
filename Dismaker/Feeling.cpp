#include "Feeling.h"

Feeling::Feeling()
{
	_feelings = FeelingMap();
}

Feeling::~Feeling()
{
}

void Feeling::AddFeeling(const std::string& id, int startingValue)
{
	_feelings[id] = startingValue;
}

void Feeling::AddToFeeling(const std::string& id, int value)
{
	_feelings[id] += value;
}

int Feeling::GetFeeling(const std::string& id)
{
	return _feelings[id]; 
}