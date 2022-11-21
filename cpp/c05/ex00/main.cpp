#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat carlo("Carl", 50);
        std::cout << carlo << std::endl;
        Bureaucrat emile("SALUT", 1000);
        std::cout << emile << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------\n";

    Bureaucrat chien("pluto", 150);
    Bureaucrat chat("garfield", 1);

    Bureaucrat copy(chat);
    std::cout << "copy : " << copy << std::endl;
    copy = chien;
    std::cout << "copy : " << copy << std::endl;

    try
    {
        chien.increment();
        chat.increment();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << chien << std::endl << chat << std::endl;
    std::cout << "-------------------\n";

    try
    {
        chat.decrement();
        chien.decrement();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << chien << std::endl << chat << std::endl;

    try
    {
        chat.decrement();
        chien.decrement();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << chien << std::endl << chat << std::endl;
}