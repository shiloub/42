#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mut;

    mut.push(5);
    mut.push(10);
    mut.push(15);
    mut.push(20);
    mut.push(25);

    std::cout << "working function size : " << mut.size() << std::endl;
    std::cout << "I remove the last element\nnew size :";
    mut.pop();
    std::cout << mut.size() << std::endl;

    std::cout << "I print my stack using iterators added by myself \n";

    MutantStack<int>::iterator beg;
    MutantStack<int>::iterator end;

    beg = mut.begin();
    end = mut.end();

    while (beg != end)
    {
        std::cout << *beg << std::endl;
        beg++;
    }
}