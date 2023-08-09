#pragma once

#include <stack>
#include <exception>

enum class Operator
{
	Plus,	// +
	Minus,	// -
	Times,	// *
	Divide,	// /
	Pow,	// ^
};

class ParseException : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "Error";
    }
};

class DivideByZeroException : public ParseException
{
public:
	virtual const char *what() const throw()
	{
		return "Error: Division by zero";
	}
};

void parseArgs(const std::string& str, std::stack<int>& numbers);
