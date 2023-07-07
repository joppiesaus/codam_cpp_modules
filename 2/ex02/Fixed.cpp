/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 16:13:36 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/05/18 15:01:59 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath> // roundf

#define EPSILON (1.0f / (float)(1 << this->fractionalBits))


Fixed::Fixed() :
	m_n(0)
{
}

// private raw bits constructor, hence the dummy argument
Fixed::Fixed(const int rawBits, const int dummy) :
	m_n(rawBits)
{
	(void)dummy;
}

Fixed Fixed::fromRawBits(const int rawBits)
{
	return Fixed(rawBits, 0);
}

Fixed::Fixed(const int i)
{
    this->m_n = i << this->fractionalBits;
}

Fixed::Fixed(const float f)
{
	this->m_n = roundf(f * (float)(1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed& fixed)
{
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->m_n = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}


int Fixed::getRawBits(void) const
{
    return this->m_n;
}

void Fixed::setRawBits(int const raw)
{
	this->m_n = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)(this->m_n) / (float)(1 << this->fractionalBits));
}

int Fixed::toInt( void ) const
{
    return (this->m_n >> this->fractionalBits);
}

std::ostream& operator<<(std::ostream &os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed Fixed::operator+(const Fixed &b) const
{
	return Fixed::fromRawBits(this->m_n + b.m_n);
}

Fixed Fixed::operator-(const Fixed &b) const
{
    return Fixed::fromRawBits(this->m_n - b.m_n);
}

Fixed Fixed::operator*(const Fixed &b) const
{
    return Fixed::fromRawBits(((long)this->m_n * (long)b.m_n) >> (this->fractionalBits));
}

Fixed Fixed::operator/(const Fixed &b) const
{
	#define SIGN_BIT ((long)1 << (sizeof(long) * 8 - 1))

	long an = (long)this->m_n;

	// the reason why we shift everything to the left is because it increases precision.
	// say you have 3.245(3245), and you divide it by 1.000(1000), then you get 3.
	// if you just shift the divisor the way over to the left, then do the division, and then
	// shift back, you can sometimes avoid losing accuracy.
	// note however, that this specific implementation relies on a long being 2x as large as an
	// int, as on many platforms is. I can't do a static_assert as that is c++11.
	// Alternatively, without casting it to a long, you can simply utilize all remaining room
	// on the left by using a loop.
	an <<= sizeof(int) * 8;
	an |= ((long)(this->m_n)) & SIGN_BIT;
	
	return Fixed::fromRawBits((int)(((an / b.m_n) << this->fractionalBits) >> (sizeof(int) * 8)));
	
	#undef SIGN_BIT
}

// pre increment/decrement
Fixed& Fixed::operator++()
{
	++this->m_n;
	return *this;
}

Fixed& Fixed::operator--()
{
	--this->m_n;
	return *this;
}

// post increment/decrement
Fixed Fixed::operator++(int)
{
	return Fixed::fromRawBits(this->m_n++);
}

Fixed Fixed::operator--(int)
{
	return Fixed::fromRawBits(this->m_n--);
}

bool operator==(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() == b.getRawBits();
}

bool operator!=(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() != b.getRawBits();
}

bool operator>(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() > b.getRawBits();
}

bool operator<(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() < b.getRawBits();
}

bool operator>=(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() >= b.getRawBits();
}

bool operator<=(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() <= b.getRawBits();
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a <= b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a >= b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a <= b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a >= b) ? a : b;
}
