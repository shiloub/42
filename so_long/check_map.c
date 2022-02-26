/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:36:16 by amontant          #+#    #+#             */
/*   Updated: 2022/02/26 15:39:25 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map)
{
	if (check_walls(map) && check_player_exit(map))
		return (1);
	else
		return (0);
}

int	check_player_exit(char **map)
{
	int	x;
	int	y;
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				p++;
			if (map[y][x] == 'E')
				e++;
			if (map[y][x] == 'C')
				c++;
			x++;
		}
	}
	return (check_if_present(p, e, c));
}

int	check_if_present(int p, int e, int c)
{
	if (p != 1)
		return (0);
	if (e == 0)
		return (0);
	if (c <= 0)
		return (0);
	return (1);
}

int	check_walls(char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[0][++x])
	{
		if (map[0][x] != '1')
			return (0);
	}
	y = 0;
	while (map[y])
	{
		if (map[y][0] != '1')
			return (0);
		y++;
	}
	x = 0;
	y --;
	while (map[y][x])
	{
		if (map[y][x] != '1')
			return (0);
		x++;
	}
	return (check_last_wall(map, x));
}

int	check_last_wall(char **map, int x)
{
	int	y;

	y = 0;
	x --;
	while (map[y])
	{
		if (map[y][x] != '1')
			return (0);
		y ++;
	}
	return (1);
}