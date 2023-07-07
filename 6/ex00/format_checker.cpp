/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_checker.cpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 18:33:52 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/06 18:35:44 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <string>

#include "stuff.hpp"

static bool isChar(const std::string& input)
{
	return (input.length() == 1 
			&& std::isprint(input[0]));
}

static bool isDouble(const std::string& input)
{
	return (is_valid_double_format(input.c_str())
		|| input == "inf"
		|| input == "+inf"
		|| input == "-inf"
		|| input == "nan");
}

static bool isFloat(std::string input)
{
	if (input.back() == 'f')
	{
		input.pop_back();
		return isDouble(input);
	}
	else
	{
		return false;
	}
	// size_t length = input.length();

	// if (length < 2 || input[length - 1] == 'f')
	// {
	// 	return false;
	// }
	// input.pop_back();
	// return is_valid_double_format(input.c_str());
}



Type::e_type getType(const std::string& input)
{
	if (is_valid_int_format(input.c_str()))
	{
		return Type::Int;
	}
	else if (isChar(input))
	{
		return Type::Char;
	}
	else if (isFloat(input))
	{
		return Type::Float;
	}
	else if (isDouble(input.c_str()))
	{
		return Type::Double;
	}
	throw InvalidException();
	return Type::Invalid;
}

static void	skip_whitespace(const char **str)
{
	while (std::isspace(**str))
	{
		(*str)++;
	}
}


bool	is_valid_int_format(const char *str)
{
	skip_whitespace(&str);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (*str == 0);
}

// stolen from my fract-ol
bool	is_valid_double_format(const char *str)
{
	const char	*str_before_numberskip;
	int			number_before_dot;

	skip_whitespace(&str);
	if (*str == '-' || *str == '+')
		str++;
	str_before_numberskip = str;
	while (*str >= '0' && *str <= '9')
		str++;
	number_before_dot = str_before_numberskip < str;
	if (*str == 0 && number_before_dot)
		return (true);
	if (*str != '.')
		return (false);
	str++;
	str_before_numberskip = str;
	while (*str >= '0' && *str <= '9')
		str++;
	if (str_before_numberskip == str && !number_before_dot)
		return (false);
	skip_whitespace(&str);
	return (*str == 0);
}
