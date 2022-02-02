#include "push_swap.h"

#include "push_swap.h"

int	find_minpos(t_intlist *lst)
{
	int	min;
	int	pos;
	t_intlist	*current;

	if (!lst)
		return (0);
	current = lst;
	pos = 0;
	min = lst->content;
	while(current != NULL)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	current = lst;
	while (current->content != min)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

int	find_maxpos(t_intlist *lst)
{
	int			max;
	int			pos;
	t_intlist	*current;

	if (!lst)
		return (0);
	current = lst;
	pos = 0;
	max = lst->content;
	while (current != NULL)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	current = lst;
	while (current->content != max)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

int	value_is_extreme(t_intlist *b, int value, int indice)
{
	t_intlist	*current;

	current = b;
	while (current)
	{
		if (current->content < value && indice == 1)
			return (0);
		else if (current->content > value && indice == 2)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_bigger_lowest(t_intlist *b, int value)
{
	t_intlist	*current;
	int			i;
	int			max_index;
	int			max_value;

	current = b;
	i = 0;
	max_index = 0;
	max_value = -2147483648;
	while (current)
	{
		if (current->content > max_value && current->content < value)
		{
			max_value = current->content;
			max_index = i;
		}
		i++;
		current = current->next;
	}
	return (max_index);
}

int	find_just_next(t_intlist *b, int value, int indice)
{
	if (indice == 1)
		return (find_bigger_lowest(b, value));
	else
		return (find_lower_biggest(b, value));
}

int	find_lower_biggest(t_intlist *b, int value)
{
	t_intlist	*current;
	int			i;
	int			min_index;
	int			min_value;

	current = b;
	i = 0;
	min_index = 0;
	min_value = 2147483647;
	while (current)
	{
		if (current->content < min_value && current->content > value)
		{
			min_value = current->content;
			min_index = i;
		}
		i++;
		current = current->next;
	}
	return (min_index);
}
