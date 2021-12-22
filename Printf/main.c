#include "display.h"
#include <stdio.h>

int main()
{
	ft_putstr("ceci est un test\n");
	ft_putnbr(-42);
	ft_putchar('\n');
	ft_putnbr_hexa(15424);
	int *p;

	*p = 24;
	printf("\n%p\n", p);
	ft_putnbr_hexa((unsigned long)&p);
	return 0;
}
