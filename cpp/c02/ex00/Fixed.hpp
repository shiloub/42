#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &rhs);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();


	private:
		int	_number;
		static const int _v = 8;
};
#endif