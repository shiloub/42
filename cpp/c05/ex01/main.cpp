#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat paul("paul", 100);

    Form form("form", 99, 5);
    paul.signForm(form);
    std::cout << form << std::endl;
    paul.increment();
    paul.signForm(form);
    std::cout << form << std::endl;
    paul.signForm(form);

    Bureaucrat lucie("lucie", 25);
    Form cpy(form);
    std::cout << cpy << std::endl;
    lucie.signForm(cpy);

    try
    {
        Form test("form", 10, 165);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form test("form", 0, 16);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
}