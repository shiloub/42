#include "lst.h"

// t_strlist	*sort_pushmin(t_intlist *a)
// {
// 	t_intlist	*b;
// 	t_intlist	*current;
// 	int			min;

// 	b = NULL;
// 	current = a;
// 	min = a->content;
// 	while (!check_sort(a, b))
// 	{
// 		while ()
// 	}




// }

int	find_minpos(t_intlist *lst)
{
	int	min;
	int	pos;
	t_intlist	*current;

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