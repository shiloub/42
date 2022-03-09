/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:17:39 by amontant          #+#    #+#             */
/*   Updated: 2022/03/09 14:17:40 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			break ;
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

int	check_rectangle(char **map)
{
	int	line_size;
	int	i;
	int	check;

	i = 0;
	line_size = 0;
	while (map[0][line_size])
		line_size++;
	while (map[i])
	{
		check = 0;
		while (map[i][check])
			check++;
		if (check != line_size)
			return (0);
		i++;
	}
	return (1);
}
