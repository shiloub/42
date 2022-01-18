/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:14:34 by amontant          #+#    #+#             */
/*   Updated: 2022/01/18 18:32:35 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_move(t_move *move, t_intlist **from, t_intlist **to, int indice)
{
	while (move->common_move)
	{
		if (move->reverse_from)
			rrr(move, from, to);
		else
			rr(move, from, to);
	}
	while (move->move_from || move->move_to)
		ra_rb(move, from, to, indice);
	if (indice == 1)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
	push(from, to);
}

void	rrr(t_move *move, t_intlist **from, t_intlist **to)
{
	reverse_rotate(from);
	reverse_rotate(to);
	move->common_move--;
	write(1, "rrr\n", 4);
}

void	rr(t_move *move, t_intlist **from, t_intlist **to)
{
	rotate(from);
	rotate(to);
	move->common_move--;
	write(1, "rr\n", 3);
}

void	ra_rb(t_move *move, t_intlist **from, t_intlist **to, int indice)
{
	if (move->move_from)
	{
		rotate(from);
		move->move_from--;
		if (indice == 1)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	if (move->move_to)
	{
		rotate(to);
		move->move_to--;
		if (indice == 1)
			write(1, "rb\n", 3);
		else
			write(1, "ra\n", 3);
	}
}
