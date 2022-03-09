/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:29:48 by amontant          #+#    #+#             */
/*   Updated: 2022/03/09 14:29:49 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*set_game(char *map_path)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	g->map = set_map(map_path);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, map_w(g->map), map_h(g->map), "so_long");
	g->wall = mlx_xpm_file_to_image(g->mlx, "wall.xpm", &g->w, &g->h);
	g->door = mlx_xpm_file_to_image(g->mlx, "door.xpm", &g->w, &g->h);
	g->robot = mlx_xpm_file_to_image(g->mlx, "robot.xpm", &g->w, &g->h);
	g->ground = mlx_xpm_file_to_image(g->mlx, "ground.xpm", &g->w, &g->h);
	g->fruit = mlx_xpm_file_to_image(g->mlx, "fruit.xpm", &g->w, &g->h);
	g->door_open = mlx_xpm_file_to_image(g->mlx, "door_open.xpm", &g->w, &g->h);
	g->x = malloc(sizeof(int));
	g->y = malloc(sizeof(int));
	*g->x = 0;
	*g->y = 0;
	return (g);
}

int	map_w(char **map)
{
	int	i;

	i = 0;
	if (!map[0])
		return (0);
	while (map[0][i])
		i++;
	return (i * 24);
}

int	map_h(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i * 24);
}
