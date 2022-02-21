/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:50:47 by amontant          #+#    #+#             */
/*   Updated: 2022/01/24 18:08:14 by shiloub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_moves(t_move *move, t_move *best_move)
{
	if (move != best_move)
	{
		free(best_move);
		free(move);
	}
	else
		free(move);
}

void	free_2(t_move *a, t_move *b, t_move *c, t_move *best_move)
{
	if (a == best_move)
	{
		free(b);
		free(c);
	}
	if (b == best_move)
	{
		free(a);
		free(c);
	}
	if (c == best_move)
	{
		free(b);
		free(a);
	}
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_freelst(t_intlist *lst)
{
	t_intlist	*temp;
	t_intlist	*current;

	current = lst;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	lst = NULL;
}
