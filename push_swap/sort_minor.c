/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_minor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:19:10 by amontant          #+#    #+#             */
/*   Updated: 2022/02/02 17:19:47 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_minor(t_intlist **a, t_intlist **b)
{
	if (ft_intlstsize(*a) == 2)
	{
		if (find_minpos(*a) == 1)
			sa_w(*a);
	}
	if (ft_intlstsize(*a) == 3)
		sort_3(a);
	if (ft_intlstsize(*a) == 4)
	{
		push_min_w(a, b);
		sort_3(a);
		pa_w(a, b);
	}
	if (ft_intlstsize(*a) == 5)
	{
		push_min_w(a, b);
		push_min_w(a, b);
		sort_3(a);
		pa_w(a, b);
		pa_w(a, b);
	}	
}

void	push_min_w(t_intlist **a, t_intlist **b)
{
	while (find_minpos(*a) != 0)
	{
		if (find_minpos(*a) <= ft_intlstsize(*a) / 2)
			ra_w(a);
		else
			rra_w(a);
	}
	pb_w(a, b);
}

void	sort_3(t_intlist **a)
{
	t_intlist	*b;

	b = NULL;
	if (check_sort(*a, b))
		return ;
	if (find_minpos(*a) == 0)
	{
		pb_w(a, &b);
		ra_w(a);
		pa_w(a, &b);
	}
	if (find_minpos(*a) == 1)
	{
		if (find_maxpos(*a) == 0)
			ra_w(a);
		else
			sa_w(*a);
		return ;
	}
	else if (find_minpos(*a) == 2)
	{
		if (find_maxpos(*a) == 0)
			sa_w(*a);
		rra_w(a);
	}
}
