#include <iostream>
float puissance(int x, int y)
{
    int i = 0;
    float res = 1;
    if (y > 0)
    {
        while (i < y)
        {
            res = res * x;
            i++;
        }
    }
    else if (y < 0)
    {
        while (i > y)
        {
            res = res / x;
            i--;
        }
    }
    int r = res * 100000000;

    while (r % 10 == 0)
        r = r / 10;
    return (r);
}
int main()
{
    float a = 96,24;

    int b = a * 1 << 8;
    std::cout <<  << std::endl;
}
