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
	char				*string;
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
t_strlist	*ft_strlstnew(char *string);
int			ft_strlstsize(t_strlist *lst);
void		ft_strlstadd_back(t_strlist **alst, t_strlist *new);
void		ft_strlstadd_front(t_strlist **alst, t_strlist *new);
void		ft_free_strlst(t_strlist *lst);
int			check_sort(t_intlist *a, t_intlist *b);
//void		sort_pushmin(t_intlist *a, t_strlist **commands);
void		print_strlst(t_strlist *lst);
void		take_op(t_intlist **a, t_intlist **b);
t_intlist 	*parsing(int ac, char **av);

#endif