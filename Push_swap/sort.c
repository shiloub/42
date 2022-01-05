#include "lst.h"

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