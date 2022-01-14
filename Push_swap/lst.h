/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:16:36 by amontant          #+#    #+#             */
/*   Updated: 2022/01/14 19:24:02 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H
# include <stdlib.h>
# include <stdio.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct s_intlist
{
	int					content;
	struct s_intlist	*next;
}			t_intlist;
typedef struct s_move
{
	int	move_a;
	int	move_b;
	int	reverse_a;
	int	reverse_b;
	int	total_move;
}		t_move;

typedef struct s_strlist
{
	char				*string;
	struct s_strlist	*next;

}	t_strlist;
//********************sort.c*****************************
int			find_minpos(t_intlist *lst);
void		sort_pushmin(t_intlist *a, t_strlist **commands);

//********************parsing.c**************************
t_intlist	*parsing(int ac, char **av);
int			check_sort(t_intlist *a, t_intlist *b);
void		take_op(t_intlist **a, t_intlist **b);
int			check_args(int ac, char **av);
int			check_nodoublons(int *tab, int size);

//********************intlst.c***************************
t_intlist	*ft_intlstnew(int content);
int			ft_intlstsize(t_intlist *lst);
void		ft_intlstadd_back(t_intlist **alst, t_intlist *new);
void		ft_intlstadd_front(t_intlist **alst, t_intlist *new);
t_intlist	*ft_intlstdup(t_intlist *lst);
void		ft_freelst(t_intlist *lst);
void		printlsts(t_intlist *a, t_intlist *b);

//*******************strlst.c****************************
int			ft_strlstsize(t_strlist *lst);
void		ft_strlstadd_back(t_strlist **alst, t_strlist *new);
void		ft_strlstadd_front(t_strlist **alst, t_strlist *new);
void		print_strlst(t_strlist *lst);
void		ft_free_strlst(t_strlist *lst);
t_strlist	*ft_strlstnew(char *string);

//*******************operation.c*************************
void		swap(t_intlist *lst);
void		push(t_intlist **from, t_intlist **to);
void		rotate(t_intlist **lst);
void		reverse_rotate(t_intlist **lst);

#endif