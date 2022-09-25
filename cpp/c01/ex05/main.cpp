#include "Harl.hpp"

#define error 1
int f()
{
    return (1);
}
int g()
{
    return (2);
}
int h()
{
    return (3);
}


int main(int ac, char **av)
{
    int i = 1;
    std::string order;

    if (ac == 1)
    {
        std::cout << "I have nothing to say :(\n";
        return (0);
    }
    Harl test;
    while (i < ac)
    {
        order = av[i];
        test.complain(order);
        i++;
    }
}