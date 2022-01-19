#include "push_swap.h"

void	set_move_from_rotate(t_move *elem, t_intlist *from, int index)
{
	elem->reverse_from = 0;
	elem->move_from = index;
}

void	set_move_to_rotate(t_move *elem, t_intlist *to, int value, int indice)
{
	int	index;
	int	count;

	count = 0;
	index = find_just_next(to, value, indice);
	if (value_is_extreme(to, value, indice) && indice == 1)
		index = find_maxpos(to);
	else if (value_is_extreme(to, value, indice) && indice == 2)
		index = find_minpos(to);
	elem->reverse_to = 0;
	elem->move_to = index;
}

void	set_move_from_reverse(t_move *elem, t_intlist *from, int index)
{
	int	count;

	count = 0;
	elem->reverse_from = 1;
	while (index <= ft_intlstsize(from) - 1)
	{
		elem->move_from++;
		index++;
	}
}

void	set_move_to_reverse(t_move *elem, t_intlist *to, int value, int indice)
{
	int	index;
	int	count;

	count = 0;
	index = find_just_next(to, value, indice);
	if (value_is_extreme(to, value, indice) && indice == 1)
		index = find_maxpos(to);
	else if (value_is_extreme(to, value, indice) && indice == 2)
		index = find_minpos(to);
	elem->reverse_to = 1;
	while (index <= ft_intlstsize(to) - 1)
	{
		elem->move_to++;
		index++;
	}
}
