// copirigt jobvan-d DO NUT STEAL!!1
#include "RPN.hpp"

#include <stack>
#include <string> // stoi
#include <iostream>

static int parseNumber(const char c)
{
    // the 1 is the "class fill constructor", so fill the string with 1 c.
    // why std::string() doesn't have a constructor for one char is beyond me
    return std::stoi(std::string(1, c));
}

static Operator parseOperator(const char c)
{
    switch (c)
    {
        case '+':
			return Operator::Plus;
		case '-':
			return Operator::Minus;
		case '*':
			return Operator::Times;
		case '/':
			return Operator::Divide;
		// case '^':
		// 	return Operator::Pow;
		default:
            throw ParseException();
			return Operator::Plus;
    }
}


// stole this function from when I needed to do typing exercises where I made
// a regular "calculator"
static void calcOne(int *cur, const int next, const Operator op)
{
    const int orig = *cur;

	switch (op)
	{
        case Operator::Plus:
            *cur = *cur + next;
            break;
        case Operator::Minus:
            *cur = *cur - next;
            break;
        case Operator::Times:
            *cur = *cur * next;
            break;
        case Operator::Divide:
            if (next == 0)
            {
                throw DivideByZeroException();
            }
            *cur = *cur / next;
            break;
        case Operator::Pow:
            *cur = 1;
            for (int i = 0; i < next; i++)
            {
                *cur *= orig;
            }
            break;
	}
}

void parseArgs(const std::string& str, std::stack<int>& numbers)
{
    bool previousCharWasToken = false;

    for (auto c : str)
    {
        // skip the spaces
        if (c == ' ')
        {
            previousCharWasToken = false;
            continue;
        }

        // if there was a token or a number before, the input is wrong.
        if (previousCharWasToken == true)
        {
            throw ParseException();
        }

        previousCharWasToken = true;
        if (std::isdigit(c))
        {
            numbers.push(parseNumber(c));
        }
        else
        {
            // when encountering an operator, pop the first two numbers on the stack, apply
            // the operation, and then put the result on the stack
            Operator op = parseOperator(c);
            if (numbers.size() < 2)
            {
                throw ParseException();
            }
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();

            calcOne(&a, b, op);
            numbers.push(a);
        }
    }

    // if there are numbers left, means that there weren't enough operators. Stop.
    if (numbers.size() > 1)
    {
        throw ParseException();
    }
    std::cout << numbers.top() << std::endl;
}
