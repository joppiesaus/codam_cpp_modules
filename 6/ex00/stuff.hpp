/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stuff.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 12:52:20 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/06 17:51:24 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// WHY CAN'T WE USE ENUM CLASS FFS
class Type
{
public:
	enum e_type { Char, Int, Float, Double, Invalid };
};

class RangeException: std::exception
{
};

class InvalidException: std::exception
{
};

Type::e_type getType(const std::string& input);

bool	is_valid_int_format(const char *str);
bool	is_valid_double_format(const char *str);
