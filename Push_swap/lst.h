#ifndef LST_H
# define LST_H
# include <stdlib.h>
# include <stdio.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct  s_intlist
{
	int                 content;
	struct s_intlist    *next;
}   t_intlist;

typedef struct	s_strlist
{
	char				*sting;
	struct s_strlist	*next;

}	t_strlist;

t_intlist	*ft_intlstnew(int content);
int	        ft_intlstsize(t_intlist *lst);
void	    ft_intlstadd_back(t_intlist **alst, t_intlist *new);
void    	ft_intlstadd_front(t_intlist **alst, t_intlist *new);
t_intlist	*ft_intlstdup(t_intlist *lst);
void	    ft_freelst(t_intlist *lst);
void        swap(t_intlist *lst);
void    	push(t_intlist **from, t_intlist **to);
void		printlsts(t_intlist *a, t_intlist *b);
void		rotate(t_intlist **lst);
void		reverse_rotate(t_intlist **lst);
int			find_minpos(t_intlist *lst);
#endif