/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/08 19:07:09 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	int size = 5;
	Array<int> intarr = Array<int>(size);
	

	for (int i = 0; i < size; i++)
	{
		intarr[i] = i * 3;	
	}

	Array<int> intarr2 = Array<int>(intarr);
	for (int i = 0; i < size; i++)
	{
		intarr2[i] = i * -2;	
	}

	intarr.display();
	intarr2.display();

	intarr2 = intarr;
	intarr2.display();

	Array<std::string> strarr = Array<std::string>(size);
	strarr[2] = "hello";
	strarr[4] = "pindakaas";
	strarr.display();

	Array<std::string> empty = Array<std::string>(0);
	empty.display();

	try
	{
		intarr[size + 6] = 9;
	}
	catch(const std::exception& e)
	{
		std::cerr << "out of range\n";
	}
	

	// system("leaks array");
	
}
