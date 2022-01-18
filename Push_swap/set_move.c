/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:23:41 by amontant          #+#    #+#             */
/*   Updated: 2022/01/18 19:24:43 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*set_move(t_intlist *from, t_intlist *to, int index, int indice)
{
	t_move	*elem;

	elem = malloc(sizeof(t_move));
	set_move_from(elem, from, index);
	set_move_to(elem, to, index_value(from, index), indice);
	set_total_move(elem);
	return (elem);
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

void	set_move_from(t_move *elem, t_intlist *from, int index)
{
	int	count;

	count = 0;
	elem->move_from = 0;
	if (index > ft_intlstsize(from) / 2)
	{
		elem->reverse_from = 1;
		while (index <= ft_intlstsize(from) - 1)
		{
			elem->move_from++;
			index++;
		}
	}
	else
	{
		elem->reverse_from = 0;
		elem->move_from = index;
	}
}

void	set_move_to(t_move *elem, t_intlist *to, int value, int indice)
{
	int	index;
	int	count;

	count = 0;
	index = find_just_next(to, value, indice);
	if (value_is_extreme(to, value, indice) && indice == 1)
		index = find_maxpos(to);
	else if (value_is_extreme(to, value, indice) && indice == 2)
		index = find_minpos(to);
	elem->move_to = 0;
	if (index > ft_intlstsize(to) / 2)
	{
		elem->reverse_to = 1;
		while (index <= ft_intlstsize(to) - 1)
		{
			elem->move_to++;
			index++;
		}
	}
	else
	{
		elem->reverse_to = 0;
		elem->move_to = index;
	}
}

void	set_total_move(t_move *elem)
{
	elem->common_move = 0;
	if (elem->reverse_from == elem->reverse_to)
	{
		while (elem->move_from && elem->move_to)
		{
			elem->move_from--;
			elem->move_to--;
			elem->common_move++;
		}
	}
	elem->total = elem->move_from + elem->move_to + elem->common_move;
}
