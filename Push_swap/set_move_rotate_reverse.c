/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_move_rotate_reverse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:18:15 by amontant          #+#    #+#             */
/*   Updated: 2022/02/02 17:59:08 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_move_from_rotate(t_move *elem, int index)
{
	elem->reverse_from = 0;
	elem->move_from = index;
}

void	set_move_to_rotate(t_move *elem, t_intlist *to, int v, int indice)
{
	int	index;

	index = find_just_next(to, v, indice);
	if (value_is_extreme(to, v, indice) && indice == 1)
		index = find_maxpos(to);
	else if (value_is_extreme(to, v, indice) && indice == 2)
		index = find_minpos(to);
	elem->reverse_to = 0;
	elem->move_to = index;
}

void	set_move_from_reverse(t_move *elem, t_intlist *from, int index)
{
	elem->reverse_from = 1;
	elem->move_from = 0;
	while (index <= ft_intlstsize(from) - 1)
	{
		elem->move_from++;
		index++;
	}
}

void	set_move_to_reverse(t_move *elem, t_intlist *to, int value, int i)
{
	int	index;

	elem->move_to = 0;
	index = find_just_next(to, value, i);
	if (value_is_extreme(to, value, i) && i == 1)
		index = find_maxpos(to);
	else if (value_is_extreme(to, value, i) && i == 2)
		index = find_minpos(to);
	elem->reverse_to = 1;
	while (index <= ft_intlstsize(to) - 1)
	{
		elem->move_to++;
		index++;
	}
}
