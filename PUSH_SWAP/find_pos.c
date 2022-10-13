/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:32:21 by amontant          #+#    #+#             */
/*   Updated: 2022/02/02 17:32:45 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minpos(t_intlist *lst)
{
	int			min;
	int			pos;
	t_intlist	*current;

	if (!lst)
		return (0);
	current = lst;
	pos = 0;
	min = lst->content;
	while (current != NULL)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	current = lst;
	while (current->content != min)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

int	find_maxpos(t_intlist *lst)
{
	int			max;
	int			pos;
	t_intlist	*current;

	if (!lst)
		return (0);
	current = lst;
	pos = 0;
	max = lst->content;
	while (current != NULL)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	current = lst;
	while (current->content != max)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}
