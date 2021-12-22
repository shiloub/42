#include "display.h"
#include <stdarg.h>

int treat(const char *str, int i, va_list arg)
{
    if (str[i + 1] == 'd' || str[i + 1] == 'i')
        {
            ft_putnbr_si()
        }

}

int ft_printf(char const *str, ...)
{
    int i;
    int count;
    va_list arg;
    va_start(arg, str);
    count = 0;
    while(str[i])
    {
        if(str[i] != '%')
            count = count + write(1, &str[i], 1);
        else if(str[i + 1])
            count = count + treat(str, i, arg);
        else
            count = count + write(1, &str[i], 1);
        i++;
    }
    va_end(args);
    return(count);
}