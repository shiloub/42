#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T>
T &min(const T &a, const T &b)
{
    if (a < b)
        return (const_cast<T &>(a));
    else
        return (const_cast<T &>(b));
}

template <typename T>
T &max(const T &a, const T &b)
{
    if (a > b)
        return (const_cast<T &>(a));
    else
        return (const_cast<T &>(b));
}

template <typename T>
void swap(T &a, T &b)
{
    T temp;

    temp = a;
    a = b;
    b = temp;
}

#endif