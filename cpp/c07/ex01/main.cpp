#include <iostream>
#include "template.hpp"

void minus(char &c)
{
    c -= 32;
}
int main()
{
    char str[7];

    str[0] = 'a';
    str[1] = 'e';
    str[2] = 'i';
    str[3] = 'o';
    str[4] = 'u';
    str[5] = 'y';
    str[6] = 0;
    iter(str, 6, &minus);

    std::cout << str << std::endl;

}