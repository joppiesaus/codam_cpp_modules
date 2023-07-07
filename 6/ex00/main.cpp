/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/06 18:32:57 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <limits>

#include "stuff.hpp"

// first, detect type, by first detecting subtypes.
// then, process it by casting it to a long double.
// then write a function to display it all,

double parse(const std::string& input, Type::e_type type)
{
	double result = 0.0;

	switch (type)
	{
		case Type::Char: {
			char c = static_cast<char>(input[0]);
			result = static_cast<long double>(c);
			break;
		}

		case Type::Int: {
			long i = std::strtol(input.c_str(), nullptr, 10);

			if (errno == ERANGE)
			{
				throw RangeException();
			}

			result = static_cast<long double>(i);
			break;
		}

		case Type::Float:
		case Type::Double:
			result = std::strtod(input.c_str(), nullptr);

			if (errno == ERANGE)
			{
				throw RangeException();
			}
			break;

		default:
			break;
	}
	return result;
}

void display(double value)
{
	bool edgecase = (value == std::numeric_limits<double>::quiet_NaN()
						|| value == std::numeric_limits<double>::infinity()
						|| value == -std::numeric_limits<double>::infinity());


	std::cout << "char:   ";
	if (!edgecase && value >= std::numeric_limits<char>::lowest() && value <= std::numeric_limits<char>::max())
	{
		char c = static_cast<char>(value);
		if (std::isprint(c))
		{
			std::cout << "\'" << c << "\'";
		}
		else
		{
			std::cout << "non displayable";
		}
	}
	else
	{
		std::cout << "impossible";
	}
	std::cout << "\n";


	std::cout << "int:    ";
	if (!edgecase && value >= std::numeric_limits<int>::lowest() && value <= std::numeric_limits<int>::max())
	{
		int i = static_cast<int>(value);
		std::cout << i;
	}
	else
	{
		std::cout << "impossible";
	}
	std::cout << "\n";

	std::cout.precision(std::numeric_limits<float>::max_digits10);
	std::cout << "float:  ";
	if (!edgecase && (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::lowest()))
	{
		std::cout << "impossible";
	}
	else
	{
		float f = static_cast<float>(value);
		std::cout << f;
	}
	std::cout << "\n";

	std::cout.precision(std::numeric_limits<double>::max_digits10);
	std::cout << "double: ";
	if (!edgecase && (value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::lowest()))
	{
		std::cout << "impossible";
	}
	else
	{
		std::cout << value;
	}
	std::cout << "\n";
}

void process(const std::string& input)
{
	Type::e_type type;
	double value;
	
	try
	{
		type = getType(input);
	}
	catch (const InvalidException& e)
	{
		std::cerr << "Invalid input\n";
	 	return;
	}

	try
	{
		value = parse(input, type);
	}
	catch (const RangeException& e)
	{
		std::cerr << "Input out of range(underflows or overflows)\n";
	 	return;
	}

	std::cout << value << std::endl;
	display(value);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <number>\n";
		return 1;
	}

	std::string input = static_cast<std::string>(argv[1]);
	process(input);
}
