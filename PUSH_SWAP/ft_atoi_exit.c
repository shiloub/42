/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:21:25 by amontant          #+#    #+#             */
/*   Updated: 2022/02/21 16:33:54 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	atoi_ex(const char *nptr, char **tab, int *int_tab, t_intlist *lst)
{
	int		i;
	int		neg;
	long	nbr;

	i = 0;
	nbr = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isnum(nptr[i]))
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
		if (nbr > 2147483648 && neg == -1)
			ft_exit(tab, int_tab, lst);
		else if (nbr > 2147483647 && neg == 1)
			ft_exit(tab, int_tab, lst);
	}
	return (nbr * neg);
}

void	ft_exit(char **tab, int *int_tab, t_intlist *lst)
{
	write(1, "Error\n", 6);
	if (tab && int_tab)
	{
		free_split(tab);
		free(int_tab);
		exit(0);
	}
	else if (lst)
	{
		ft_freelst(lst);
		exit(0);
	}
	exit(0);
}
