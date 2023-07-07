#pragma once

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& fixed);
	Fixed& operator=(const Fixed& other);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int m_n;
	static const int fractionalBits = 8;
};
