#include "so_long.h"

int	go_left(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (map[i][j - 1] != '1' && map[i][j - 1] != 'E')
				{
					map[i][j - 1] = 'P';
					map[i][j] = '0';
					return (1);
				}
			}
		j++;
		}
		i++;
	}
	return (0);
}

int	go_right(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (map[i][j + 1] != '1' && map[i][j + 1] != 'E')
				{
					map[i][j + 1] = 'P';
					map[i][j] = '0';
					return (1);
				}
			}
		j++;
		}
		i++;
	}
	return (0);
}
int	go_up(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (map[i + 1][j] != '1' && map[i + 1][j] != 'E')
				{
					map[i + 1][j] = 'P';
					map[i][j] = '0';
					return (1);
				}
			}
		j++;
		}
		i++;
	}
	return (0);
}

int	go_down(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (map[i - 1][j] != '1' && map[i - 1][j] != 'E')
				{
					map[i - 1][j] = 'P';
					map[i][j] = '0';
					return (1);
				}
			}
		j++;
		}
		i++;
	}
	return (0);
}
