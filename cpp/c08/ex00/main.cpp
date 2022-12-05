#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> oui;

    oui.push_back(1);
    oui.push_back(2);
    oui.push_back(3);
    oui.push_back(5);
    oui.push_back(5);
    oui.push_back(6);
    oui.push_back(7);

    easyfind(oui, 7);
    
}