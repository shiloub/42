#include "math.h"
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->_number = 0;
}
Fixed::Fixed(const int raw)
{
	std::cout << "Integer constructor called\n";
	this->_number = raw;
	this->_number = this->_number << this->_v;
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called\n";
	this->_number = (int)(roundf(raw * (1 << this->_v)));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called\n";
	this->_number = fixed.getRawBits();
	return (*this);
}

std::ostream &operator << ( std::ostream &st ,const Fixed &rhs )
{
	float f = rhs.toFloat();
	st << f;
	return (st);
}


float	Fixed::toFloat(void) const
{
	float f = (float)this->_number / (float)(1 << this->_v);
	return (f);
}

int		Fixed::toInt(void) const
{
	return (this->_number >> 8);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member fonction called\n";
	return (this->_number);
}

void Fixed::setRawBits( int const raw )
{
	this->_number = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}