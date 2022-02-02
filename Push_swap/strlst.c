/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:20:46 by amontant          #+#    #+#             */
/*   Updated: 2022/02/02 17:33:21 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strlist	*ft_strlstnew(char *string)
{
	t_strlist	*new;

	new = malloc(sizeof(t_strlist));
	if (!new)
		return (NULL);
	new->string = string;
	new->next = NULL;
	return (new);
}

int	ft_strlstsize(t_strlist *lst)
{
	t_strlist	*current;
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

void	ft_strlstadd_back(t_strlist **alst, t_strlist *new)
{
	t_strlist	*current;

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

void	ft_strlstadd_front(t_strlist **alst, t_strlist *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_free_strlst(t_strlist *lst)
{
	t_strlist	*temp;
	t_strlist	*current;

	current = lst;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->string);
		free(temp);
	}
	lst = NULL;
}
