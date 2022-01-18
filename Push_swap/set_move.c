#include "push_swap.h"

void	set_move(t_move *elem, t_intlist *a, t_intlist *b, int index)
{
	set_move_a(elem, a, index);
	set_move_b(elem, b, index_value(a, index));
	set_total_move(elem);
}
int	index_value(t_intlist *lst, int index)
{
	t_intlist	*current;

	current = lst;
	while (index > 0)
	{
		current = current->next;
		index--;
	}
	return (current->content);
}

void    set_move_a(t_move *elem, t_intlist *a, int index)
{
	int count;

	count = 0;
	elem->move_a = 0;
	if (index > ft_intlstsize(a) / 2)
	{
		elem->reverse_a = 1;
		while (index <= ft_intlstsize(a) - 1)
		{
			elem->move_a++;
			index++;
		}
	}
	else
	{
		elem->reverse_a = 0;
		elem->move_a = index;
	}
}
void    set_move_b(t_move *elem, t_intlist *b, int value)
{
	int index;
	int count;

	count = 0;
	index = find_bigger_lowest(b, value);
	if (value_is_lowest(b, value))
		index = find_maxpos(b);
	elem->move_b = 0;
	if (index > ft_intlstsize(b) / 2)
	{
		elem->reverse_b = 1;
		while (index <= ft_intlstsize(b) - 1)
		{
			elem->move_b++;
			index++;
		}
	}
	else
	{
		elem->reverse_b = 0;
		elem->move_b = index;
	}
}

void	set_total_move(t_move *elem)
{
	elem->common_move = 0;
	if (elem->reverse_a == elem->reverse_b)
	{
		while(elem->move_a && elem->move_b)
		{
			elem->move_a--;
			elem->move_b--;
			elem->common_move++;
		}
	}
	elem->total = elem->move_a + elem->move_b + elem->common_move;
}