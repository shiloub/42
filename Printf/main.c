#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	// i = ft_printf("salut je m'appelle % et j'ai %d%s et le pointeur de i = %p", "jon", 22, "ans", &i);
	// ft_printf("\n retour = %d\n", i);
	i = printf("salut je m'appelle % et j'ai %d%s et le pointeur de i = %p", "jon", 22, "ans", &i);
	printf("\n retour = %d\n", i);
}
