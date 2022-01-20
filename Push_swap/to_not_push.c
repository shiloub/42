#include "push_swap.h"

void	printlsts(t_intlist *a, t_intlist *b)
{
	t_intlist	*current_a;
	t_intlist	*current_b;

	current_a = a;
	current_b = b;
	printf("*********\n");
	printf("|a     b|\n");
	printf("*********\n");
	while(current_a && current_b)
	{
		printf(" %d     %d\n", current_a->content, current_b->content);
		current_a = current_a->next;
		current_b = current_b->next;
	}
	while(current_a)
	{
		printf(" %d\n", current_a->content);
		current_a = current_a->next;
	}
	while(current_b)
	{
		printf("       %d\n", current_b->content);
		current_b = current_b->next;
	}
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
void	take_op(t_intlist **a, t_intlist **b)
{
	char	*str;
	t_move *move;
	int	count = 0;
	while (1)
	{
		str = get_next_line(1);
		if (!ft_strncmp(str, "sa\n", 100))
			swap(*a);
		else if (!ft_strncmp(str, "sb\n", 100))
			swap(*b);
		else if (!ft_strncmp(str, "ss\n", 100))
		{
			swap(*a);
			swap(*b);	
		}
		else if (!ft_strncmp(str, "pa\n", 100))
			push(b, a);
		else if (!ft_strncmp(str, "pb\n", 100))
			push(a, b);
		else if (!ft_strncmp(str, "ra\n", 100))
			rotate(a);
		else if (!ft_strncmp(str, "rb\n", 100))
			rotate(b);
		else if (!ft_strncmp(str, "rr\n", 100))
		{
			rotate(a);
			rotate(b);
		}
		else if (!ft_strncmp(str, "rra\n", 100))
			reverse_rotate(a);
		else if (!ft_strncmp(str, "rrb\n", 100))
			reverse_rotate(b);
		else if (!ft_strncmp(str, "rrr\n", 100))
		{
			reverse_rotate(a);
			reverse_rotate(b);
		}
		else if (!ft_strncmp(str, "move\n", 100))
		{
			move = set_move(*a, *b, 3, 1);
			print_move(move);
		}
		else if (!ft_strncmp(str, "exec\n", 100))
		{
			exec_move(move, a, b, 1);
		}
		else if (!ft_strncmp(str, "stop\n", 100))
			break;
		else
		{
			printf("\nwrong command\n");
			count--;	
		}
		count++;
		printlsts(*a, *b);
		free(str);
		if (check_sort(*a, *b))
		{
			printf("\n\n\n***********You won, your score is %d***********\n\n\n", count);
			break;
		}	
	}
}
