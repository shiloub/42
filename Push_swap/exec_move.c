#include "push_swap.h"

void	exec_move(t_move *move, t_intlist **a, t_intlist **b)
{
	while (move->common_move)
	{
		if (move->reverse_a)
			rrr(move, a, b);
		else
			rr(move, a, b);
	}
	while (move->move_a || move->move_b)
		ra_rb(move, a, b);
	push(a, b);
	write(1, "pb\n", 3);
}
void	rrr(t_move *move, t_intlist **a, t_intlist **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	move->common_move--;
	write(1, "rrr\n", 4);
}

void	rr(t_move *move, t_intlist **a, t_intlist **b)
{
	rotate(a);
	rotate(b);
	move->common_move--;
	write(1, "rr\n", 3);
}

void	ra_rb(t_move *move, t_intlist **a, t_intlist **b)
{
	if(move->move_a)
	{
		rotate(a);
		move->move_a--;
		write(1, "ra\n", 3);
	}
	if(move->move_b)
	{
		rotate(b);
		move->move_b--;
		write(1, "rb\n", 3);
	}
}