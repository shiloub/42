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

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called\n";
	this->_number = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed f(this->toFloat() + rhs.toFloat());
	return (f);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed f(this->toFloat() - rhs.toFloat());
	return (f);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed f(this->toFloat() * rhs.toFloat());
	return (f);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	if (rhs.getRawBits() == 0)
	{
		std::cout << "ERROR division by 0 is undefined\n";
		exit(0);
	}
	Fixed f(this->toFloat() / rhs.toFloat());
	return (f);
}

Fixed	&Fixed::operator++(void)
{
	this->_number ++;
	return (*this);
}

Fixed	Fixed::operator++(int number)
{
	Fixed temp = *this;


	if (number != 0)
		this->_number += number;
	else
		this->_number++;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	this->_number --;
	return (*this);
}

Fixed	Fixed::operator--(int number)
{
	Fixed temp = *this;


	if (number != 0)
		this->_number -= number;
	else
		this->_number--;
	return (temp);
}

bool		Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool		Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool		Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool		Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool		Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool		Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}


std::ostream &operator << ( std::ostream &st ,const Fixed &rhs )
{
	float f = rhs.toFloat();
	st << f;
	return (st);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
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