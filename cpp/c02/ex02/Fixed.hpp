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
		Fixed	&operator=(const Fixed &rhs);
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;
		Fixed	&operator++(void);
		Fixed	operator++(int number);
		Fixed	&operator--(void);
		Fixed	operator--(int number);
		static	Fixed	&min(Fixed &a, Fixed &b);
		static	const Fixed	&min(const Fixed &a, const Fixed &b);
		static	Fixed	&max(Fixed &a, Fixed &b);
		static	const Fixed	&max(const Fixed &a, const Fixed &b);
		bool  	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs)	const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
		~Fixed();


	private:
		int	_number;
		static const int _v = 8;
};
		std::ostream &operator << ( std::ostream &st, const Fixed &rhs);
#endif