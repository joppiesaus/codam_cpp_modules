/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/08 14:32:54 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

int main()
{
	std::string strings[] =
	{
		"apple",
		"pear",
		"orange",
		"banana",
		"ananas"
	};

	int ints[] = { 5, 2, 3, 1, 6 };

	iter<std::string>(strings, 5, print<std::string>);
	iter<int>(ints, 5, print<int>);
}
