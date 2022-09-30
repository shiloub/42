#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->_number = 0;
}
Fixed::Fixed(const int raw)
{
	this->_number = raw;
	this->_number = this->_number << this->_v;
}

Fixed::Fixed(const float raw)
{

	float test = raw * (1 << this->_v);
	this->_number = (int)test;
	int save = this->_number;
	int f = 0;
	std::cout << this->_number << std::endl;
	this->_number = this->_number >> 8;
	std::cout << (this->_number << 24 >> 24) << std::endl;


	this->_number = save;
	std::cout << this->_number << std::endl;
	int i = 0;
	int j = 8;

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