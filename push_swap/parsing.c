/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:58:59 by shiloub           #+#    #+#             */
/*   Updated: 2022/02/22 15:54:11 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intlist	*parsing(int ac, char **av)
{
	t_intlist	*stack;
	t_intlist	*new;
	int			temp;

	temp = ac;
	stack = NULL;
	new = NULL;
	if (ac == 2)
		stack = parsing_long_string(av[1]);
	else
	{
		if (!check_args(ac, av))
			return (NULL);
		stack = ft_intlstnew(atoi_ex(av[--temp], NULL, NULL, stack));
		while (temp >= 2)
		{
			new = ft_intlstnew(atoi_ex(av[--temp], NULL, NULL, stack));
			ft_intlstadd_front(&stack, new);
		}
	}
	return (stack);
}

t_intlist	*parsing_long_string(char *str)
{
	int			i;
	t_intlist	*stack;
	int			*int_tab;
	char		**tab;

	i = 0;
	if (!check_only_digit(str))
		return (NULL);
	tab = ft_split(str, ' ');
	if (tab == NULL)
		return (NULL);
	int_tab = set_int_tab(tab);
	while (tab[i] != NULL)
		i++;
	if (!check_nodoublons(int_tab, i))
	{
		free_split(tab);
		return (NULL);
	}
	stack = NULL;
	while (i > 0)
		ft_intlstadd_front(&stack, ft_intlstnew(ft_atoi(tab[--i])));
	free_split(tab);
	return (stack);
}

int	*set_int_tab(char **tab)
{
	int	*int_tab;
	int	size;

	size = 0;
	while (tab[size] != NULL)
		size ++;
	int_tab = malloc(sizeof(int) * size);
	size = 0;
	while (tab[size] != NULL)
	{
		int_tab[size] = atoi_ex(tab[size], tab, int_tab, NULL);
		size ++;
	}
	return (int_tab);
}
