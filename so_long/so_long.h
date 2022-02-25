#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"

int		check_map(char **map);
int		check_walls(char **map);
int		check_last_wall(char **map, int x);
void	throw_away_the_cr(char *str);
void	free_map(char **map);
char	**set_map(char *map_path);
int		count_line(char *map_path);

#endif