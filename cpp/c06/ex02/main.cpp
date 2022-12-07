#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "function.hpp"

int main()
{
    Base *test;

    test = generate();
    Base *a= new A;
    Base *b= new B;
    Base *c= new C;
    identify(test);
    identify(*test);
    std::cout << "_____________________\n";
    identify(a);
    identify(b);
    identify(c);
    std::cout << "again\n";
    identify(*a);
    identify(*b);
    identify(*c);
    delete a;
    delete b;
    delete c;
    delete test;

}