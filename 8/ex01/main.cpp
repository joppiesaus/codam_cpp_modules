/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/14 14:07:03 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>

int main()
{
	std::cout << "the basics\n";
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		try
		{
			sp.addNumber(24);
		}
		catch (const Span::SpanFullException& e)
		{
			std::cerr << "Can't add number to span: " << e.what() << std::endl;
		}
	}

	std::cout << "max/min int test\n";
	{
		Span sp = Span(3);
		sp.addNumber(-2147483648);
		sp.addNumber(2147483640);
		sp.addNumber(2147483647);
		

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "empty span:\n";
	{
		Span sp = Span();
		
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const Span::NotEnoughNumbers& ex)
		{
			std::cerr << ex.what() << '\n';
		}
	}

	std::cout << "span with too little numbers:\n";
	{
		Span sp = Span(5);

		sp.addNumber(2);
		
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const Span::NotEnoughNumbers& ex)
		{
			std::cerr << ex.what() << '\n';
		}
	}

	std::cout << "Filling with random\n";
	{
		Span s = Span(10000);
		s.fillRandom();

		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}

	std::cout << "Adding a range\n";
	{
		int length = 100000;

		Span s = Span(length);
		std::vector<int> vec = std::vector<int>();

		for (int i = 0; i < length; i++)
		{
			vec.push_back(i + i / 100);
		}

		s.fillRange(vec.begin(), vec.end());

		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;

		vec.push_back(0xfa1af3l);

		std::cout << "Trying a range which is too large\n";
		try
		{
			s.fillRange(vec.begin(), vec.end());
		}
		catch (const Span::SpanFullException& e)
		{
			std::cerr << "Can't add number to span: " << e.what() << std::endl;
		}
		
	}
}
