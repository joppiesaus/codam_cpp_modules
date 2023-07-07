/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:54:05 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/08 14:03:54 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#include <iostream>

int main()
{
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	std::cout << "\n\n";

	{
		int a = 6;
		int b = 10;

		std::cout << "a: " << a << ", b: " << b << std::endl;
		swap<int>(a, b);
		std::cout << "a: " << a << ", b: " << b << std::endl;	

		std::cout << "min: " << min<int>(a, b) << std::endl;
		std::cout << "max: " << max<int>(a, b) << std::endl;
	}

	{
		float a = 59.59;
		float b = 3.141592;

		std::cout << "a: " << a << ", b: " << b << std::endl;
		swap<float>(a, b);
		std::cout << "a: " << a << ", b: " << b << std::endl;	

		std::cout << "min: " << min<float>(a, b) << std::endl;
		std::cout << "max: " << max<float>(a, b) << std::endl;
	}
}
