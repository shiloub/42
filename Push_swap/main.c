#include "push_swap.h"

int main(int ac, char **av)
{
	t_intlist	*a;
	t_intlist *b;
	a = parsing(ac, av);
	b = NULL;
	sort(&a, &b);
	//printlsts(a, b);
	//take_op(&a, &b);
	ft_freelst(a);
	ft_freelst(b);
	return (0);
}

void	sort(t_intlist **a, t_intlist **b)
{
	push(a, b);
	push(a, b);
	write(1, "pb\npb\n", 6);
	push_in_b(a, b);
	push_in_a(a, b);
	while (find_minpos(*a) != 0)
	{
		if (find_minpos(*a) + 1 > ft_intlstsize(*a) / 2)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
	}
}

void	push_in_b(t_intlist **a, t_intlist **b)
{
	t_move		*move;
	t_move		*best_move;
	t_intlist	*current;
	int			i;

	while (ft_intlstsize(*a) > 2)
	{
		current = *a;
		best_move = set_move(*a, *b, 0, 1);
		i = 0;
		while (current)
		{
			move = set_move(*a, *b, i, 1);
			if (best_move->total > move->total)
				set_best_move(best_move, move);
			current = current->next;
			i++;
		}
		exec_move(best_move, a, b, 1);
		if(move != best_move)
		{
			free(best_move);
			free(move);
		}
		else
			free(move);
		
	}
}

void	push_in_a(t_intlist **a, t_intlist **b)
{
	t_move		*move;
	t_move		*best_move;
	t_intlist	*current;
	int			i;

	move = malloc(sizeof(t_move));
	best_move = malloc(sizeof(t_move));
	current = *b;
	while (ft_intlstsize(*b) > 0)
	{
		best_move = set_move(*b, *a, 0, 2);
		i = 0;
		while (current)
		{
			move = set_move(*b, *a, i, 2);
			if (best_move->total > move->total)
				set_best_move(best_move, move);
			current = current->next;
			i++;
		}
		exec_move(best_move, b, a, 2);
		//free(move);
		//free(best_move);
	}
}

void	set_best_move(t_move *best_move, t_move *move)
{
	best_move->move_from = move->move_from;
	best_move->move_to = move->move_to;
	best_move->reverse_from = move->reverse_from;
	best_move->reverse_to = move->reverse_to;
	best_move->common_move = move->common_move;
	best_move->total = move->total;
}

void	print_move(t_move *move)
{
	printf("move_from = %d\n", move->move_from);
	printf("move_to = %d\n", move->move_to);
	printf("reverse_from = %d\n", move->reverse_from);
	printf("reverse_to = %d\n", move->reverse_to);
	printf("common_move = %d\n", move->common_move);
	printf("total = %d\n", move->total);
}
