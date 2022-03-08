/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:37:41 by amontant          #+#    #+#             */
/*   Updated: 2022/03/05 16:16:56 by shiloub          ###   ########.fr       */
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
# include "gnl/get_next_line.h"
#include "mlx_linux/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	//int		*win_height;
	//int		*win_width;
	char	**map;
	void	*ground;
	void	*wall;
	void	*robot;
	void	*door;
	void	*fruit;
	void	*door_open;
	int		img_height;
	int		img_width;
	int		*x;
	int		*y;
	
}	t_game;

int		check_map(char **map);
int		check_walls(char **map);
int		check_last_wall(char **map, int x);
int		check_player_exit(char **map);
int		check_if_present(int p, int e, int c);
void	throw_away_the_cr(char *str);
void	free_map(char **map);
char	**set_map(char *map_path);
int		count_line(char *map_path);
t_game	*set_game(char *map_path);
int		map_width(char **map);
int		map_height(char **map);
void	print_map(t_game *game);
void	print_texture(t_game *game, char c, int x, int y);
int		go_left(char **map);
int		go_down(char **map);
int		go_up(char **map);
int		go_right(char **map);
void	open_door_if_necessary(char **map);
void	change_door(char **map);
void    free_game(t_game *game);
void    exit_game(t_game *game);
int		no_door(char **map);


#endif