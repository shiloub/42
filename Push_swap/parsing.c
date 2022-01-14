/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:58:59 by shiloub           #+#    #+#             */
/*   Updated: 2022/01/14 19:28:54 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lst.h"
#include <stdio.h>

// t_intlist	*parsing(int ac, char **tab)
// {
// 	t_intlist	*stack;
// 	int			temp;

// 	temp = ac;
// 	stack = ft_intlstnew(ft_atoi(tab[--temp]));
// 	while (temp >= 2)
// 		ft_intlstadd_front(&stack, ft_intlstnew(ft_atoi(tab[--temp])));
// 	return (stack);
// }

// int	check_sort(t_intlist *a, t_intlist *b)
// {
// 	t_intlist	*current;
// 	int			max;

// 	if (ft_intlstsize(b))
// 		return (0);
// 	current = a;
// 	max = current->content;
// 	while (current)
// 	{
// 		if (max > current->content)
// 			return (0);
// 		max = current->content;
// 		current = current->next;
// 	}
// 	return (1);
// }

int	check_args(int ac, char **av)
{
	int	*tab;
	int	i;
	int	size;

	tab = malloc(sizeof(int) * (ac - 1));
	size = ac - 1;
	if (!tab)
		return (0);
	while (ac >= 2)
	{
		i = 0;
		while (av[ac - 1][i])
		{
			if (!ft_isdigit(av[ac - 1][i]))
			{
				free(tab);
				return (0);
			}
			i++;
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

// void	take_op(t_intlist **a, t_intlist **b)
// {
// 	char	*str;
// 	int	count = 0;
// 	while (1)
// 	{
// 		str = get_next_line(1);
// 		if (!ft_strncmp(str, "sa\n", 100))
// 			swap(*a);
// 		else if (!ft_strncmp(str, "sb\n", 100))
// 			swap(*b);
// 		else if (!ft_strncmp(str, "ss\n", 100))
// 		{
// 			swap(*a);
// 			swap(*b);	
// 		}
// 		else if (!ft_strncmp(str, "pa\n", 100))
// 			push(b, a);
// 		else if (!ft_strncmp(str, "pb\n", 100))
// 			push(a, b);
// 		else if (!ft_strncmp(str, "ra\n", 100))
// 			rotate(a);
// 		else if (!ft_strncmp(str, "rb\n", 100))
// 			rotate(b);
// 		else if (!ft_strncmp(str, "rr\n", 100))
// 		{
// 			rotate(a);
// 			rotate(b);
// 		}
// 		else if (!ft_strncmp(str, "rra\n", 100))
// 			reverse_rotate(a);
// 		else if (!ft_strncmp(str, "rrb\n", 100))
// 			reverse_rotate(b);
// 		else if (!ft_strncmp(str, "rrr\n", 100))
// 		{
// 			reverse_rotate(a);
// 			reverse_rotate(b);
// 		}
// 		else if (!ft_strncmp(str, "minpos\n", 100))
// 		{
// 			printf("\nle min est en %d position\n", find_minpos(*a));
// 		}
// 		else if (!ft_strncmp(str, "size\n", 100))
// 		{
// 			printf("\nla size le la liste a est %d\n", ft_intlstsize(*a));
// 		}
// 		else if (!ft_strncmp(str, "stop\n", 100))
// 			break;
// 		else
// 		{
// 			printf("\nwrong command\n");
// 			count--;	
// 		}
// 		count++;
// 		printlsts(*a, *b);
// 		free(str);
// 		if (check_sort(*a, *b))
// 		{
// 			printf("\n\n\n***********You won, your score is %d***********\n\n\n", count);
// 			break;
// 		}	
// 	}
// }
