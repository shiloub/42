/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:18:05 by amontant          #+#    #+#             */
/*   Updated: 2022/01/15 16:24:04 by shiloub          ###   ########.fr       */
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

void	ft_freelst(t_intlist *lst)
{
	t_intlist	*temp;
	t_intlist	*current;

	current = lst;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	lst = NULL;
}

void	printlsts(t_intlist *a, t_intlist *b)
{
	t_intlist	*current_a;
	t_intlist	*current_b;

	current_a = a;
	current_b = b;
	printf("*********\n");
	printf("|a     b|\n");
	printf("*********\n");
	while(current_a && current_b)
	{
		printf(" %d     %d\n", current_a->content, current_b->content);
		current_a = current_a->next;
		current_b = current_b->next;
	}
	while(current_a)
	{
		printf(" %d\n", current_a->content);
		current_a = current_a->next;
	}
	while(current_b)
	{
		printf("       %d\n", current_b->content);
		current_b = current_b->next;
	}
}
