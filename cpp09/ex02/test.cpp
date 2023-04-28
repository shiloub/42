#include <iostream>
#include <vector>


int main()
{
    size_t y = -1;

    std::cout << y << std::endl;
    std::vector<int> a;
    std::vector<int> b;

    a.push_back(1);
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);

    b = a;
    for(size_t i = 0; i < b.size(); i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    return (0);
}