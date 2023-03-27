#include <string>
#include <iostream>
#include <array>
#include <stdlib.h>
#include <list>

void    print_list(std::list<int> list)
{
    std::list<int>::iterator it = list.begin();
    while (it != list.end())
    {
        std::cout << *it << " ";
        it ++;
    }
    std::cout << std::endl;
}

void insertion_sort_list(std::list<int> &list)
{
    int i = 0;
    int j = 0;
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator temp;
    
    while (it != list.end())
    {
        it ++;
        temp = it;
        while (it != list.end())
        {
            
        }
    }


}

int main(int ac, char **av)
{
    if (ac == 1)
        return (0);

    std::list<int> test;
    while (ac > 1)
    {
        test.push_front(atoi(av[ac - 1]));
        ac --;
    }
    print_list(test);
    return (0);
}