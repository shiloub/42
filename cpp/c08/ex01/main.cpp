#include "Span.hpp"
#include "iostream"
#include "time.h"

int main()
{
    Span sp = Span(8);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::vector<int> to_add;
    to_add.push_back(21);
    to_add.push_back(2);
    to_add.push_back(31);

    sp.add_by_it(to_add.begin(), to_add.end());
    std::cout << "After add : \n";
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "i try to add a 9th number (max is 8)\n";
    try
    {
        sp.addNumber(8);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    std::cout << "\n--------------------\n";
    srand((unsigned)time(NULL));
    Span span(10000);

    for (int i = 0;   i < 10000; i++)
        span.addNumber(rand() % 4000000000);

    //span.print();
    //std::cout << "\n--------------\n";
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;
    std::cout << "try to longest spawn an empty span :\n";
    Span error(10);
    try
    {
        std::cout << error.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "error : " << e.what() << '\n';
    }
    

}