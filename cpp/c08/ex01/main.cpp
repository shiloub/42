#include "Span.hpp"
#include "iostream"
#include "time.h"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n--------------------\n";
    srand((unsigned)time(NULL));
    Span span(10000);

    for (int i = 0;   i < 10000; i++)
        span.addNumber(rand() % 4000000000);

    span.print();
    std::cout << "\n--------------\n";
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;

    Span error(10);
    try
    {
        std::cout << error.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}