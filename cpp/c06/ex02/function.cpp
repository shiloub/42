
#include "function.hpp"

Base *generate()
{
    time_t timer;

    time(&timer);
	if (timer % 3 == 0)
    {
        A *newA = new A;
        return (newA);
    }
    if (timer % 3 == 1)
    {
        B *newB = new B;
        return (newB);
    }
    C *newC = new C;
    return (newC);
}

void    identify(Base *p)
{
    A *a = dynamic_cast<A*>(p); 
    if (a != 0)
    {
        std::cout << "its an A\n";
    }

    B *b = dynamic_cast<B*>(p); 
    if (b != 0)
    {
        std::cout << "its a B\n";
    }
    C *c = dynamic_cast<C*>(p); 
    if (c != 0)
    {
        std::cout << "its a C\n";
    }

}

void identify(Base &p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "its an A\n";

    }
    catch(const std::exception& e)
    {}
    
    try
    {
        B b = dynamic_cast<B&>(p);
        std::cout << "its a B\n";

    }
    catch(const std::exception& e)
    {
    } 
    
    try
    {
        C c = dynamic_cast<C&>(p);
        std::cout << "its a C\n";

    }
    catch(const std::exception& e)
    {
    }
}