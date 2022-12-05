#include <algorithm>
#include <string>
#include <iostream>

template <typename T>
void easyfind(T cont, int n)
{
	typename    T::const_iterator it;

    it = std::find(cont.begin(), cont.end(), n);
    if (it != cont.end())
    {
        std::cout << "Value found" << std::endl;
    }
    else
    {
        throw (std::string("Value doesn't exist in the container."));
    }
}