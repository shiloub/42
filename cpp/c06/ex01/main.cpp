#include "data.hpp"
#include "deserielize.hpp"
#include <iostream>

int main()
{
    Data test;
    Data *cpy;
    uintptr_t buf;

    test.c = 'a';
    test.i = 21;
    test.s = "salut";

    std::cout << "before : data address : " << &test << std::endl;
    buf = serialize(&test);
    cpy = deserialize(buf);
    std::cout << "after : data address : " << cpy << std::endl;
    std::cout << cpy->c << std::endl << cpy->i << std::endl << cpy->s << std::endl;

}