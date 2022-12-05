#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T>
void iter(T* tab, int size, void (*f) (const T &))
{
    for (int i = 0; i < size; i++)
    {
        f(tab[i]);
    }
}

#endif