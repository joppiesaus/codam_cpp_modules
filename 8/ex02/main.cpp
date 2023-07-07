/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/14 14:02:57 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
	std::cout << "Subject test:\n";
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "Own tests: mutant stack:\n";
	{
		MutantStack<int> ms;

		ms.push(1);
		ms.push(2);
		ms.push(3);
		ms.push(4);
		ms.push(5);
		ms.push(6);

		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++)
		{
			*it = *it + 1;
			std::cout << *it << ", ";
		}
		std::cout << std::endl;
		for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); it++)
		{
			*it = *it + 1;
			std::cout << *it << ", ";
		}
		std::cout << std::endl;

		ms.pop();

		for (MutantStack<int>::const_iterator it = ms.begin(); it != ms.end(); it++)
		{
			std::cout << *it << ", ";
		}
		std::cout << std::endl;
		for (MutantStack<int>::const_reverse_iterator it = ms.rbegin(); it != ms.rend(); it++)
		{
			std::cout << *it << ", ";
		}
		std::cout << std::endl;
	}

	std::cout << "list:\n";
	{
		std::list<int> li = std::list<int>();

		li.push_back(1);
		li.push_back(2);
		li.push_back(3);
		li.push_back(4);
		li.push_back(5);
		li.push_back(6);

		for (std::list<int>::iterator it = li.begin(); it != li.end(); it++)
		{
			*it = *it + 1;
			std::cout << *it << ", ";
		}
		std::cout << std::endl;
		for (std::list<int>::reverse_iterator it = li.rbegin(); it != li.rend(); it++)
		{
			*it = *it + 1;
			std::cout << *it << ", ";
		}
		std::cout << std::endl;

		li.pop_back();

		for (std::list<int>::const_iterator it = li.begin(); it != li.end(); it++)
		{
			std::cout << *it << ", ";
		}
		std::cout << std::endl;
		for (std::list<int>::const_reverse_iterator it = li.rbegin(); it != li.rend(); it++)
		{
			std::cout << *it << ", ";
		}
		std::cout << std::endl;
	}
}
