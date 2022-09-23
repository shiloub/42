#include <iostream>
#include <string>

int main()
{
    std::string brain("HI THIS IS BRAIN");
    std::string *stringPTR;
    std::string &stringREF = brain;

    stringPTR = &brain;
    std::cout << "addresse de la string en memoire : " << &brain << std::endl;
    std::cout << "addresse stockée dans stringPTR : " << stringPTR << std::endl;
    std::cout << "addresse stockée dans stringREF : " << &stringREF << std::endl;

    std::cout << "affichage par la sring : " << brain << std::endl;
    std::cout << "affichage par stringPTR : " << *stringPTR << std::endl;
    std::cout << "affichage par stringREF : " << stringREF << std::endl;

    return 0;
}