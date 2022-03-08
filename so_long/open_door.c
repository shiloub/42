#include "so_long.h"

void	open_door_if_necessary(char **map)
{
	int	i;
	int	j;
	int	count_fruit;

	i = 0;
	count_fruit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count_fruit ++;
			j++;
		}
		i++;
	}
	if (count_fruit == 0)
		change_door(map);
}

void	change_door(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				map[i][j] = 'O';
			j++;
		}
		i++;
	}
}

int	no_door(char **map)
{
	int	door;
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'O')
				return(0);
			j++;
		}
		i++;
	}
	return (1);
}