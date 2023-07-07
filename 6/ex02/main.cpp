/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 20:49:17 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/07 17:13:55 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <random>
#include <iostream>

Base* generate(void)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distribution(0, 3);

	switch (distribution(mt))
	{
		default:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return new Base(); // should never be reached
};

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a != nullptr)
	{
		std::cout << "class A";
		return;
	}

	B *b = dynamic_cast<B*>(p);
	if (b != nullptr)
	{
		std::cout << "class B";
		return;
	}

	C *c = dynamic_cast<C*>(p);
	if (c != nullptr)
	{
		std::cout << "class C";
		return;
	}

	std::cout << "Unknown!";
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "class A";
		return;
	}
	catch (const std::bad_cast& e)
	{
	}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "class B";
		return;
	}
	catch (const std::bad_cast& e)
	{
	}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "class C";
		return;
	}
	catch (const std::bad_cast& e)
	{
	}

	std::cout << "Unkown!";
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Base *base = generate();

		std::cout << "passed by pointer: ";
		identify(base);

		std::cout << ", passed by reference: ";
		identify(*base);

		std::cout << std::endl;

		delete base;
	}
}
