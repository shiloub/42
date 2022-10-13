/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:20:23 by amontant          #+#    #+#             */
/*   Updated: 2022/02/02 17:20:24 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_w(t_intlist *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	ra_w(t_intlist **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	pb_w(t_intlist **a, t_intlist **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa_w(t_intlist **a, t_intlist **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	rra_w(t_intlist **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
