/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:09:24 by amontant          #+#    #+#             */
/*   Updated: 2022/02/18 19:58:54 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			return (0);
		if (i == 0 && str[i] == '-')
			i++;
		else if (i > 0 && str[i - 1] == ' ' && str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
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
	int	size;

	if (ac <= 2)
		return (0);
	tab = malloc(sizeof(int) * (ac - 1));
	size = ac - 1;
	if (!tab)
		return (0);
	while (ac >= 2)
	{
		if (!check_only_digit2(av[ac - 1]))
		{
			free(tab);
			return (0);
		}
		tab[ac - 2] = ft_atoi(av[ac - 1]);
		ac--;
	}
	return (check_nodoublons(tab, size));
}

int	check_only_digit2(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] == '-')
		i++;
	if (nbr[0] == '-' && !ft_isdigit(nbr[1]))
		return (0);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
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
