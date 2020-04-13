#include "CommandInputBridge.h"
#include <iostream>	
#include <sstream>

CommandInputBridge::CommandInputBridge()
{
}

CommandInputBridge::~CommandInputBridge()
{
}

std::string CommandInputBridge::GetText()
{
	std::string reuslt;
	std::getline(std::cin, reuslt);

	const char* fuck = reuslt.c_str();

	return reuslt;
}
