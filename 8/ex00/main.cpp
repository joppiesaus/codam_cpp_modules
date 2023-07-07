/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/10 17:37:12 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <list>
#include <iostream>

template <class T, class I>
void checkfound(T container, I i)
{
	typename T::iterator it = easyfind(container, i);

	if (it != container.end())
	{
		std::cout << "found: " << *it << "\n";
	}
	else
	{
		std::cout << "not found :(\n";
	}
}

int main()
{
	std::vector<int> ivec = std::vector<int>();

	std::list<size_t> list = std::list<size_t>();

	ivec.push_back(5);
	ivec.push_back(90);
	ivec.push_back(84);
	ivec.push_back(57);

	checkfound(ivec, 90);
	checkfound(ivec, 80);

	list.push_back(500);
	list.push_back(8);
	list.push_back(0);
	list.push_back(9);
	list.push_back(56);

	checkfound(list, 8);
	checkfound(list, 575);
}
