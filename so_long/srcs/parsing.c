/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:17:39 by amontant          #+#    #+#             */
/*   Updated: 2022/03/10 17:12:27 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
	if (!map[0] || !check_map(map))
	{
		free_map(map);
		return (NULL);
	}
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
