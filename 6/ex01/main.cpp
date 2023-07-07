/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 20:49:17 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/06 20:54:24 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
	int derp;
	long yeet;
	char *ayy;
};

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}


int main()
{
	Data data = Data();

	Data *dataptr = &data;
	uintptr_t ptr = serialize(dataptr);

	std::cout << dataptr << std::endl;
	std::cout << ptr << std::endl;
	Data *newdataptr = deserialize(ptr);
	std::cout << newdataptr << std::endl;
}
