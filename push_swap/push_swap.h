/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:16:36 by amontant          #+#    #+#             */
/*   Updated: 2022/02/22 15:58:13 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_intlist
{
	int					content;
	struct s_intlist	*next;
}			t_intlist;
typedef struct s_move
{
	int	move_from;
	int	move_to;
	int	reverse_from;
	int	reverse_to;
	int	common_move;
	int	total;
}		t_move;

typedef struct s_strlist
{
	char				*string;
	struct s_strlist	*next;

}	t_strlist;
//*******************position.c*************************
int			find_minpos(t_intlist *lst);
int			find_maxpos(t_intlist *lst);
int			find_just_next(t_intlist *b, int value, int indice);
int			find_bigger_lowest(t_intlist *b, int value);
int			find_lower_biggest(t_intlist *b, int value);
int			value_is_extreme(t_intlist *b, int value, int indice);

//********************parsing.c**************************
t_intlist	*parsing(int ac, char **av);
t_intlist	*parsing_long_string(char *str);
int			*set_int_tab(char **tab);

//********************check_parsing.c********************
int			check_sort(t_intlist *a, t_intlist *b);
int			check_args(int ac, char **av);
int			check_nodoublons(int *tab, int size);
int			check_only_digit(char *str);
int			check_only_digit2(char *nbr);

//********************intlst.c***************************
t_intlist	*ft_intlstnew(int content);
int			ft_intlstsize(t_intlist *lst);
void		ft_intlstadd_back(t_intlist **alst, t_intlist *new);
void		ft_intlstadd_front(t_intlist **alst, t_intlist *new);
t_intlist	*ft_intlstdup(t_intlist *lst);

//*******************strlst.c****************************
int			ft_strlstsize(t_strlist *lst);
void		ft_strlstadd_back(t_strlist **alst, t_strlist *new);
void		ft_strlstadd_front(t_strlist **alst, t_strlist *new);
t_strlist	*ft_strlstnew(char *string);

//*******************operation.c*************************
void		swap(t_intlist *lst);
void		push(t_intlist **from, t_intlist **to);
void		rotate(t_intlist **lst);
void		reverse_rotate(t_intlist **lst);

//**********************set_move.c****************************
t_move		*set_move(t_intlist *from, t_intlist *to, int index, int indice);
void		set_move_from(t_move *elem, t_intlist *from, int index);
void		set_move_to(t_move *elem, t_intlist *to, int value, int indice);
void		set_total_move(t_move *elem);
int			index_value(t_intlist *lst, int index);

//*************set_move_rotate_reverse.c**********************
void		set_move_from_rotate(t_move *elem, int index);
void		set_move_to_rotate(t_move *elem, t_intlist *to, int v, int indice);
void		set_move_from_reverse(t_move *elem, t_intlist *from, int index);
void		set_move_to_reverse(t_move *elem, t_intlist *to, int v, int indice);

//********************exec_move.c*****************************
void		exec_move(t_move *move, t_intlist **from, t_intlist **to, int i);
void		rrr(t_move *move, t_intlist **a, t_intlist **b);
void		rr(t_move *move, t_intlist **a, t_intlist **b);
void		exec_r_rr_from(t_move *move, t_intlist **from, int indice);
void		exec_r_rr_to(t_move *move, t_intlist **to, int indice);

//*********************push_swap.c*******************************
void		sort(t_intlist **a, t_intlist **b);
void		set_best_move(t_move *best_move, t_move *move);
void		print_move(t_move *move);
void		push_in_b(t_intlist **a, t_intlist **b);
void		push_in_a(t_intlist **a, t_intlist **b);

//*********************sort_minor.c************************
void		sort_3(t_intlist **a);
void		sort_minor(t_intlist **a, t_intlist **b);
void		push_min_w(t_intlist **a, t_intlist **b);

//***********************free.c****************************
void		free_moves(t_move *a, t_move *b);
void		ft_freelst(t_intlist *lst);
void		free_split(char **tab);
void		free_2(t_move *a, t_move *b, t_move *c, t_move *best_move);
void		ft_free_strlst(t_strlist *lst);

//*********************to_not_push.c***********************
//void		printlsts(t_intlist *a, t_intlist *b);
//void		sort_pushmin(t_intlist *a, t_strlist **commands);
//void		take_op(t_intlist **a, t_intlist **b);

//*********************write_op.c***************************
void		sa_w(t_intlist *a);
void		ra_w(t_intlist **a);
void		pb_w(t_intlist **a, t_intlist **b);
void		pa_w(t_intlist **a, t_intlist **b);
void		rra_w(t_intlist **a);

//*********************ft_atoi_exit*************************
int			atoi_ex(const char *nptr, char **tab, int *int_tab, t_intlist *lst);
void		ft_exit(char **tab, int *int_tab, t_intlist *lst);

//**********************checker.c***************************
int			do_op(t_intlist **a, t_intlist **b, t_strlist *op);
void		get_instructions(t_strlist **lst);
int			do_op_2(t_intlist **a, t_intlist **b, char *str);
int			ft_return(void);
#endif