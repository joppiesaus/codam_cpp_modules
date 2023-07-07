/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 14:15:11 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/08 19:07:57 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <class T>
void print(const T& t)
{
	std::cout << t << std::endl;
}


// template <class T, void F(const T&)> <-- doesn't work
template <class T, typename F>
void iter(T array[], size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}
