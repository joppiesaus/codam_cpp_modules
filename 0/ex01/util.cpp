#include "util.hpp"

#include <stdlib.h> // exit

#define WHITESPACE_CHARS (" \t\n\r\v\f")

static void trimStart(std::string &str)
{
	size_t startPos = str.find_first_not_of(WHITESPACE_CHARS);
	if (startPos != str.npos && startPos > 0)
	{
		str = str.substr(startPos);
	}
}

// this is a bit inefficient, as it always substrings the string, but whatever.
static void trimEnd(std::string &str)
{
	size_t startPos = str.find_last_not_of(WHITESPACE_CHARS);
	if (startPos != str.npos)
	{
		str = str.substr(0, startPos + 1);
	}
}

void my_getline(std::string &str)
{
	do
	{
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			exit(0);
		}
	} while (str.find_first_not_of(WHITESPACE_CHARS) == str.npos);
	trimStart(str);
	trimEnd(str);
}
