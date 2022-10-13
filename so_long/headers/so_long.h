/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:37:41 by amontant          #+#    #+#             */
/*   Updated: 2022/03/10 16:58:56 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../srcs/printf/ft_printf.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*ground;
	void	*wall;
	void	*robot;
	void	*door;
	void	*fruit;
	void	*door_open;
	int		h;
	int		w;
	int		*x;
	int		*y;
	int		*count;
}	t_game;
//*********************check_map.c***********************//
int		check_map(char **map);

//*********************check_map_ft.c********************//
int		check_walls(char **map);
int		check_last_wall(char **map, int x);
int		check_player_exit(char **map);
int		check_rectangle(char **map);
int		check_if_present(int p, int e, int c);

//*********************parsing.c*************************//
void	throw_away_the_cr(char *str);
char	**set_map(char *map_path);
int		count_line(char *map_path);

//*********************set.c*****************************//
t_game	*set_game(char *map_path);
int		map_w(char **map);
int		map_h(char **map);

//*******************print_map.c************************//
void	print_map(t_game *game);
void	print_texture(t_game *game, char c, int x, int y);

//***********************move.c*************************//
int		go_left(char **map);
int		go_down(char **map);
int		go_up(char **map);
int		go_right(char **map);

//*********************open_door.c**********************//
void	open_door_if_necessary(char **map);
int		no_door(char **map);
void	change_door(char **map);

//**************************finish.c********************//
void	free_game(t_game *game);
void	free_map(char **map);
void	exit_game(t_game *game);

int		ft_printf(char const *str, ...);
#endif