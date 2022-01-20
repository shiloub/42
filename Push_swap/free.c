/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:50:47 by amontant          #+#    #+#             */
/*   Updated: 2022/01/20 18:02:09 by amontant         ###   ########.fr       */
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
