#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &new_fixed);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();


	private:
		int	_number;
		static const int _v = 8;
};
#endif