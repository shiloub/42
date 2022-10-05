#include "Fixed.hpp"
#include <stdio.h>


// int main()
// {
//     Fixed const b( 50 );
//     Fixed c( 42.42f );
//     Fixed const a = b + c;
//     if (b > c)
//         std::cout << "b > c" << std::endl;
//     else
//         std::cout << "b < c" << std::endl;
//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
//     std::cout << "c = " << c << std::endl;
//     std::cout << "++c = " << ++c << std::endl;
//     std::cout << "c ++ = " << c++ << std::endl;
//     std::cout << "c = " << c << std::endl;
//     return 0;
// }

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}