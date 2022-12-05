#include "array.hpp"

int main()
{
    Array<int> fail(2000000000);
    Array<char> tab(5);
    Array<int> fail2 = fail;


    std::cout << "-----------------------\n";
    std::cout << tab << "\n-----------------------\n";
    tab[0] = 'a';
    tab[1] = 'b';
    tab[2] = 'c';
    tab[3] = 'd';
    tab[4] = 'e';

    try
    {
        tab[5] = 'f'; // error;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------------------\n";


    
    Array<char> tab2 = tab;
    std::cout << tab2 << std::endl;

    Array<char> tab3(10);

    tab3 = tab2;

    tab2[4] = 'x';
    std::cout << tab2 << std::endl;
    std::cout << tab << std::endl;
    std::cout << "-----------------------\n";
    
    Array<int> inttab(3);
    std::cout << inttab << "size : " << inttab.size() << std::endl;


}