#include "push_swap.h"

void	sort_pushmin(t_intlist *a, t_strlist **commands)
{
	t_intlist	*b;
	b = NULL;
	while (1)
	{
		if(find_minpos(a) < ft_intlstsize(a) / 2)
		{
			while (find_minpos(a) != 1)
			{
				rotate(&a);
				ft_strlstadd_back(commands, ft_strlstnew("ra"));
			}
			push(&a, &b);
			ft_strlstadd_back(commands, ft_strlstnew("pb"));
		}
		else
		{
			while (find_minpos(a) != 1)
			{
				reverse_rotate(&a);
				ft_strlstadd_back(commands, ft_strlstnew("rra"));
			}
			push(&a, &b);
			ft_strlstadd_back(commands, ft_strlstnew("pb"));
		}
		if (!ft_intlstsize(a))
		{
			while (ft_intlstsize(b))
			{
				push(&b, &a);
				ft_strlstadd_back(commands, ft_strlstnew("pa"));
			}
			return ;
		}
	}
}

int	find_minpos(t_intlist *lst)
{
	int	min;
	int	pos;
	t_intlist	*current;

	if (!lst)
		return (0);
	current = lst;
	pos = 1;
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
	int	max;
	int	pos;
	t_intlist	*current;

	if (!lst)
		return (0);
	current = lst;
	pos = 0;
	max = lst->content;
	while(current != NULL)
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

int	value_is_lowest(t_intlist *b, int value)
{
	t_intlist	*current;

	current = b;
	while (current)
	{
		if (current->content < value)
			return (0);
		current = current->next;
	}
	return (1);
}

int find_bigger_lowest(t_intlist *b, int value)
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

