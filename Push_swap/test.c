#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include "test.h"
#include <stdio.h>

// void	sort_pushmin(t_intlist *a, t_strlist **commands)
// {
// 	t_intlist	*b;
// 	b = NULL;
	
// 	while (find_minpos(a) != 1)
// 	{
// 			rotate(&a);
// 			ft_strlstadd_back(commands, ft_strlstnew("ra"));
// 	}
// 	push(&a, &b);
// 	ft_strlstadd_back(commands, ft_strlstnew("pb"));
// 	if (!check_sort(a, b))
// 		printf("\n c'est pas trié\n");
// }

void	sort_pushmin(t_intlist *a, t_strlist **commands)
{
	t_intlist	*b;
	b = NULL;
	while (1)
	{
		if(find_minpos(a) <= (ft_intlstsize(a) / 2))
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

int main(int ac, char **av)
{
	t_intlist *a;
	t_intlist *b;
	t_strlist *c;

	b = NULL;
	c = NULL;

	a = parsing(ac, av);
	printlsts(a, b);
	sort_pushmin(a, &c);
	print_strlst(c);
	return 0;
}
