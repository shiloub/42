#include <map>
#include <iostream>
#include <string>

int main()
{
    std::map<std::string, int> test;
    test.insert(std::make_pair("salut", 20));
    test.insert(std::make_pair("oui", 10));
    test.insert(std::make_pair("non", 42));
    std::map<std::string, int>::const_iterator it;
    it = test.begin();
    while (it != test.end())
    {
        std::cout << it->first << " equivaut a " << it->second << std::endl;
        it++;
    }
    return (0);
}