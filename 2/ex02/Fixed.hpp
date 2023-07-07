/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 16:13:37 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/13 12:32:13 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	~Fixed();
	Fixed(const Fixed& fixed);
	Fixed& operator=(const Fixed& other);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed operator+(const Fixed &b) const;
	Fixed operator-(const Fixed &b) const;
	Fixed operator*(const Fixed &b) const;
	Fixed operator/(const Fixed &b) const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator--(int);
	Fixed operator++(int);

	static Fixed fromRawBits(const int rawBits);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	
private:
	Fixed(const int rawBits, const int dummy);

	int m_n;
	static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed& fixed);

bool operator>(const Fixed& a, const Fixed& b);
bool operator<(const Fixed& a, const Fixed& b);
bool operator>=(const Fixed& a, const Fixed& b);
bool operator<=(const Fixed& a, const Fixed& b);
bool operator==(const Fixed& a, const Fixed& b);
bool operator!=(const Fixed& a, const Fixed& b);
