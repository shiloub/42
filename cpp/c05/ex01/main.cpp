#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // try
    // {
    //     Bureaucrat carlo("Carl", 50);
    //     std::cout << carlo << std::endl;
    //     Bureaucrat emile("SALUT", 1000);
    //     std::cout << emile << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << "-------------------\n";

    // Bureaucrat chien("pluto", 150);
    // Bureaucrat chat("garfield", 1);
    // try
    // {
    //     chien.increment();
    //     chat.increment();
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << chien << std::endl << chat << std::endl;
    // std::cout << "-------------------\n";

    // try
    // {
    //     chat.decrement();
    //     chien.decrement();
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << chien << std::endl << chat << std::endl;

    // try
    // {
    //     chat.decrement();
    //     chien.decrement();
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << chien << std::endl << chat << std::endl;

    Bureaucrat paul("paul", 100);

    Form form("form", 150, 5);
    paul.signForm(form);
    paul.signForm(form);

}