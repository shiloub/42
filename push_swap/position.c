/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:09:07 by amontant          #+#    #+#             */
/*   Updated: 2022/02/02 17:32:10 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value_is_extreme(t_intlist *b, int value, int indice)
{
	t_intlist	*current;

	current = b;
	while (current)
	{
		if (current->content < value && indice == 1)
			return (0);
		else if (current->content > value && indice == 2)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_bigger_lowest(t_intlist *b, int value)
{
	t_intlist	*current;
	int			i;
	int			max_index;
	int			max_value;

	current = b;
	i = 0;
	max_index = 0;
	max_value = -2147483648;
	while (current)
	{
		if (current->content > max_value && current->content < value)
		{
			max_value = current->content;
			max_index = i;
		}
		i++;
		current = current->next;
	}
	return (max_index);
}

int	find_just_next(t_intlist *b, int value, int indice)
{
	if (indice == 1)
		return (find_bigger_lowest(b, value));
	else
		return (find_lower_biggest(b, value));
}

int	find_lower_biggest(t_intlist *b, int value)
{
	t_intlist	*current;
	int			i;
	int			min_index;
	int			min_value;

	current = b;
	i = 0;
	min_index = 0;
	min_value = 2147483647;
	while (current)
	{
		if (current->content < min_value && current->content > value)
		{
			min_value = current->content;
			min_index = i;
		}
		i++;
		current = current->next;
	}
	return (min_index);
}
