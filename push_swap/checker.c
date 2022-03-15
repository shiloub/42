/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:10:56 by amontant          #+#    #+#             */
/*   Updated: 2022/02/25 18:02:26 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_intlist	*a;
	t_intlist	*b;
	t_strlist	*instruc;

	if (ac == 1)
		return (0);
	a = parsing(ac, av);
	if (!a)
		return (ft_return());
	b = NULL;
	instruc = NULL;
	get_instructions(&instruc);
	if (!do_op(&a, &b, instruc))
		write (1, "Error\n", 6);
	else if (check_sort(a, b))
		write (1, "OK\n", 3);
	else
		write(1, "KO\n", 4);
	ft_free_strlst(instruc);
	ft_freelst(a);
	ft_freelst(b);
	return (0);
	return (1);
}

int	ft_return(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	get_instructions(t_strlist **lst)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		ft_strlstadd_back(lst, ft_strlstnew(str));
		str = get_next_line(0);
	}
}

int	do_op(t_intlist **a, t_intlist **b, t_strlist *op)
{
	t_strlist	*current;

	current = op;
	while (current)
	{
		if (!ft_strncmp(current->string, "sa\n", 4))
			swap(*a);
		else if (!ft_strncmp(current->string, "sb\n", 4))
			swap(*b);
		else if (!ft_strncmp(current->string, "pa\n", 4))
			push(b, a);
		else if (!ft_strncmp(current->string, "pb\n", 4))
			push(a, b);
		else if (!ft_strncmp(current->string, "ra\n", 4))
			rotate(a);
		else if (!ft_strncmp(current->string, "rb\n", 4))
			rotate(b);
		else
		{
			if (!do_op_2(a, b, current->string))
				return (0);
		}
		current = current->next;
	}
	return (1);
}

int	do_op_2(t_intlist **a, t_intlist **b, char *str)
{
	if (!ft_strncmp(str, "rrr\n", 5))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else if (!ft_strncmp(str, "rr\n", 4))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp(str, "ss\n", 4))
	{
		swap(*a);
		swap(*b);
	}
	else if (!ft_strncmp(str, "rra\n", 4))
	{
		reverse_rotate(a);
	}
	else if (!ft_strncmp(str, "rrb\n", 5))
		reverse_rotate(b);
	else
		return (0);
	return (1);
}
