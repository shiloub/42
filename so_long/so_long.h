/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:37:41 by amontant          #+#    #+#             */
/*   Updated: 2022/02/26 15:37:51 by amontant         ###   ########.fr       */
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

int		check_map(char **map);
int		check_walls(char **map);
int		check_last_wall(char **map, int x);
int		check_player_exit(char **map);
int		check_if_present(int p, int e, int c);
void	throw_away_the_cr(char *str);
void	free_map(char **map);
char	**set_map(char *map_path);
int		count_line(char *map_path);

#endif