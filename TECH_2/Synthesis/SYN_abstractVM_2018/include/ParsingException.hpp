#include <exception>
#pragma once

struct ParsingFileNotFound : public std::exception
{
	const char *what() const throw ()
	{
		return ("[ERROR] file not found.");
	}
};

struct ParsingFileSyntax : public std::exception
{
	const char *what() const throw ()
	{
		return ("[ERROR] Syntax error.");
	}
};

struct ParsingUknownType : public std::exception
{
	const char *what() const throw ()
	{
		return ("[ERROR] Uknown variable type.");
	}
};
