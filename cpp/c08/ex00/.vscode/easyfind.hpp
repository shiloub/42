#include <algorithm>

template <typename T>
void easyfind(T cont, int n)
{
	typename    T::const_iterator it;

    it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
    {
        std::cout << "Value found" << std::endl;
    }
    else
    {
        throw (std::string("Value doesn't exist in the container."));
    }
}