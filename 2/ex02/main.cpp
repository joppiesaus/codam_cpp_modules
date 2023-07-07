/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 16:13:34 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/18 15:05:16 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int main()
{
	Fixed a;
	Fixed const b( 10 );
	Fixed c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f ) / Fixed( 1.0f );
	std::cout << "a is " << a << std::endl;
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	a = Fixed(0);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << Fixed( 5.05f ) * Fixed( 2 ) << std::endl;

	std::cout << Fixed::max(a, c)++ << std::endl;
	std::cout << Fixed::min(a, c) << std::endl;
	std::cout << a << " < " << b << ": " << (a < b) << std::endl;
	std::cout << a << " > " << b << ": " << (a > b) << std::endl;
	std::cout << a << " >= " << b << ": " << (a >= b) << std::endl;
	std::cout << a << " <= " << a <<  ": " << (a <= a) << std::endl;
	std::cout << a << " == " << a <<  ": " << (a == a) << std::endl;
	std::cout << a << " == " << (a + Fixed::fromRawBits(1)) <<  ": " << (a == (a + Fixed::fromRawBits(1))) << std::endl;
	
	std::cout << a << " >= " << (a + Fixed::fromRawBits(1)) <<  ": " << (a >= (a + Fixed::fromRawBits(1))) << std::endl;
	std::cout << a << " <= " << (a + Fixed::fromRawBits(1)) <<  ": " << (a <= (a + Fixed::fromRawBits(1))) << std::endl;
	std::cout << a << " != " << (a + Fixed::fromRawBits(1)) <<  ": " << (a != (a + Fixed::fromRawBits(1))) << std::endl;

	std::cout << "epsilon test: " << a << " == " << (a.toFloat() + 0.00001f) <<  ": " << (a == (Fixed(a.toFloat() + 0.00001f))) << std::endl;

	Fixed e = Fixed(390.6f);
	a = a + Fixed(1245.34f);
	std::cout << a << " / " << e <<  ": " << (a / e) << std::endl;
	std::cout << a << " * " << e <<  ": " << (a * e) << std::endl;
	std::cout << a << " + " << e <<  ": " << (a + e) << std::endl;
	std::cout << a << " - " << e <<  ": " << (a - e) << std::endl;


	a = Fixed(12321);
	e = Fixed(111);
	std::cout << a << " / " << e <<  ": " << (a / e) << std::endl;
	std::cout << a << " * " << e <<  ": " << (a * e) << std::endl;
	std::cout << a << " + " << e <<  ": " << (a + e) << std::endl;
	std::cout << a << " - " << e <<  ": " << (a - e) << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;



	a = Fixed();
	Fixed const g( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << g << std::endl;
	std::cout << Fixed::max( a, g ) << std::endl;

	return 0;
}
