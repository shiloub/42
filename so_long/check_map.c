#include "so_long.h"

int	check_map(char **map)
{
	if (check_walls(map))
		return (1);
	else
		return (0);
}

int	check_walls(char **map)
{
	int	x;
	int	y;

	x = 0;
	while(map[0][x])
	{
		if(map[0][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while(map[y])
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