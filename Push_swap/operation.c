/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:18:22 by amontant          #+#    #+#             */
/*   Updated: 2022/01/17 21:40:50 by shiloub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_intlist *lst)
{
	t_intlist	*current;
	int			temp;

	if (ft_intlstsize(lst) < 2)
		return ;
	current = lst;
	temp = current->content;
	current->content = current->next->content;
	current->next->content = temp;
}

void	push(t_intlist **from, t_intlist **to)
{
	t_intlist	*temp;

	temp = *from;
	if (!*to && temp)
	{
		*to = ft_intlstnew(temp->content);
		*from = temp->next;
		free(temp);
	}
	else if (temp)
	{
		ft_intlstadd_front(to, ft_intlstnew(temp->content));
		*from = temp->next;
		free(temp);
	}
}

void	reverse_rotate(t_intlist **lst)
{
	t_intlist	*current;

	current = *lst;
	if (!current || ft_intlstsize(current) < 2)
		return ;
	while (current->next->next)
		current = current->next;
	current->next->next = *lst;
	*lst = current->next;
	current->next = NULL;
}

void	rotate(t_intlist **lst)
{
	t_intlist	*current;

	current = *lst;
	if (!current || ft_intlstsize(current) < 2)
		return ;
	while (current->next)
		current = current->next;
	current->next = *lst;
	current = *lst;
	*lst = current->next;
	current->next = NULL;
}
