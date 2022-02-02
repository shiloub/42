#include "push_swap.h"

void    sa_w(t_intlist *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void    ra_w(t_intlist **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void    pb_w(t_intlist **a, t_intlist **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void    pa_w(t_intlist **a, t_intlist **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void    rra_w(t_intlist **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}