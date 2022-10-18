#include "Fixed.hpp"
#include <stdio.h>


int main( void ) {
    Fixed a;
    Fixed c;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
    a = Fixed(5.5f);
    c = Fixed(2.5f);
    std::cout << "a = " << a << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "a + c = " << a + c << std::endl;
    std::cout << "a - c = " << a - c << std::endl;
    std::cout << "a  / c = " << a / c << std::endl;
    if (a >= c)
        std::cout << "a is higher or equal to c" << std::endl;
    if (a < c)
        std::cout << "a is strictly lower than c" << std::endl;
    return 0;
}