/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:58:59 by shiloub           #+#    #+#             */
/*   Updated: 2022/01/20 18:04:01 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

t_intlist	*parsing(int ac, char **av)
{
	t_intlist	*stack;
	int			temp;

	temp = ac;
	if (!check_args(ac, av))
	{
		write(1, "WRONG ARGUMENTS\n", 16);
		return (NULL);
	}
	stack = ft_intlstnew(ft_atoi(av[--temp]));
	while (temp >= 2)
		ft_intlstadd_front(&stack, ft_intlstnew(ft_atoi(av[--temp])));
	return (stack);
}

int	check_sort(t_intlist *a, t_intlist *b)
{
	t_intlist	*current;
	int			max;

	if (ft_intlstsize(b))
		return (0);
	current = a;
	max = current->content;
	while (current)
	{
		if (max > current->content)
			return (0);
		max = current->content;
		current = current->next;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	*tab;
	int	i;
	int	size;

	if (ac <= 2)
		return (0);
	tab = malloc(sizeof(int) * (ac - 1));
	size = ac - 1;
	if (!tab)
		return (0);
	while (ac >= 2)
	{
		i = -1;
		while (av[ac - 1][i++])
		{
			if (!ft_isdigit(av[ac - 1][i]))
			{
				free(tab);
				return (0);
			}
		}
		tab[ac - 2] = ft_atoi(av[ac - 1]);
		ac--;
	}
	return (check_nodoublons(tab, size));
}

int	check_nodoublons(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(tab);
	return (1);
}
