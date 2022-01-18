#include "push_swap.h"

int main(int ac, char **av)
{
	t_intlist	*a;
	t_intlist *b;
	t_move	*move;
	a = parsing(ac, av);
	b = NULL;
	sleep(0);
	move = malloc(sizeof(t_move));
	printlsts(a, b);
	printf("\n_________________________\n");
	push(&a, &b);
	push(&a, &b);
	//push(&a, &b);
	// t_intlist current;
	// current = a;
	int i = 0;
	while (i < 5)
	{
		set_move(move, a, b, 0);
		exec_move(move, &a, &b);
		i++;
	}
	while (i >= -1)
	{
		push(&b, &a);
		write(1, "pa\n", 3);
		i--;
	}
	printf("_________________________\n");
	//printf("\nmaxpos b = %d\n", find_maxpos(b));
	//printf("\nindex value(a, 2) = %d", index_value(a, 2));
	//printf("\nvalue is lowest(b, 2) = %d\n", value_is_lowest(b, 2));
	printlsts(a, b);
	
	//take_op(&a, &b);
	ft_freelst(a);
	ft_freelst(b);
	return 0;
}