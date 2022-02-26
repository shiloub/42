#include "so_long.h"

int	count_line(char *map_path)
{
	int		fd_map;
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	fd_map = open(map_path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd_map);
		if (!line)
			break;
		free(line);
		count ++;
	}
	close(fd_map);
	return (count);
}

char	**set_map(char *map_path)
{
	int		fd_map;
	char	**map;
	int		i;

	i = 0;
	fd_map = open(map_path, O_RDONLY);
	map = malloc(sizeof(char *) * (count_line(map_path) + 1));
	while (1)
	{
		map[i] = get_next_line(fd_map);
		throw_away_the_cr(map[i]);
		if (!map[i])
			break ;
		i++;
	}
	close(fd_map);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	throw_away_the_cr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		i ++;
	}
	if (str[i - 1] == '\n')
		str[i - 1] = 0;
}

int main(int ac, char **av)
{
	char	**map;
	int		i;
	int		j;

	map = set_map(av[1]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", (int)map[i][j]);
			j ++;
		}
		printf("\n");
		i++;
	}
	if (check_map(map) == 1)
		printf("map ok\n");
	else
		printf("map KO");
	free_map(map);
	return 0;
}