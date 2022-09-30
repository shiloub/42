#include "Fixed.hpp"
#include <stdio.h>

int main()
{
    float f = 25.75f; //1 10000011 10011100000000000000000
                   //sign expo             mantisse

    Fixed test(f);
    return 0;
}