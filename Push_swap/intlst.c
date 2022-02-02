/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:18:05 by amontant          #+#    #+#             */
/*   Updated: 2022/02/02 17:14:41 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intlist	*ft_intlstdup(t_intlist *lst)
{
	t_intlist	*dup;
	t_intlist	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	dup = ft_intlstnew(temp->content);
	temp = temp->next;
	while (temp != NULL)
	{
		ft_intlstadd_back(&dup, ft_intlstnew(temp->content));
		temp = temp->next;
	}
	return (dup);
}

t_intlist	*ft_intlstnew(int content)
{
	t_intlist	*new;

	new = malloc(sizeof(t_intlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_intlstsize(t_intlist *lst)
{
	t_intlist	*current;
	int			i;

	if (!lst)
		return (0);
	current = lst;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	ft_intlstadd_back(t_intlist **alst, t_intlist *new)
{
	t_intlist	*current;

	if (!alst || *alst == NULL)
	{
		*alst = new;
		return ;
	}
	current = *alst;
	if (!new)
		return ;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

void	ft_intlstadd_front(t_intlist **alst, t_intlist *new)
{
	new->next = *alst;
	*alst = new;
}
