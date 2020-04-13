#include "PaulTils.h"
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <string>
#include <direct.h>
#include <sstream>
#include <iostream>

int PaulTils::StringToInt(const char* string)
{
	std::string stdString = string;

	// Checks if it is in hex format
	if(stdString.find("0x") != std::string::npos || stdString.find("#") != std::string::npos)
	{
		unsigned int reuslt;

		std::stringstream stringstream;
		stringstream << std::hex << stdString;
		stringstream >> reuslt;

		return reuslt;
	}
	else 
	{
		std::string::size_type sz;

		return std::stoi(stdString.c_str(), &sz);
	}
}

double PaulTils::StringToDouble(const char* string)
{
	std::string::size_type sz;

	return std::stod(string, &sz);
}

float PaulTils::StringToFloat(const char* string)
{
	std::string::size_type sz;

	return (float)std::stod(string, &sz);
}

std::string PaulTils::ToLower(const char* str)
{
	std::string newString = str;

	for(size_t i = 0; i < newString.length(); i++)
	{
		newString[i] = tolower(str[i]);
	}

	return newString;
}

bool PaulTils::CaseInsensitiveStringCompare(const char* str1, const char* str2)
{
	return std::strcmp(ToLower(str1).c_str(), ToLower(str2).c_str()) == 0;
}

bool PaulTils::CaseInsensitiveStringCompare(std::string str1, std::string str2)
{
	return CaseInsensitiveStringCompare(str1.c_str(), str2.c_str());
}

bool PaulTils::FileExists(const char *fileName)
{
	std::ifstream ifile(fileName);

	return (bool) ifile;
}

bool PaulTils::FileExists(std::string fileName)
{
	return FileExists(fileName.c_str());
}

std::string PaulTils::GetCurrentDir()
{
	char* cwd = _getcwd(0, 0);
	std::string working_directory(cwd);
	std::free(cwd);
	return working_directory;
}
