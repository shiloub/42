/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:25:13 by shiloub           #+#    #+#             */
/*   Updated: 2023/02/02 00:08:38 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_lines(char **map)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i][0])
			count ++;
		i++;
	}
	return (count + 1);
}

int	check_empty_line_map(char **map)
{
	int	i;
	int	j;
	int	map_start;

	i = 0;
	map_start = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (ft_strfind("10", map[i][j]))
			map_start = 1;
		if (map[i][0] == 0 && map_start)
		{
			printf("empty line in map\n");
			free_tab(map);
			return (1);
		}
		i++;
	}
	return (0);	
}

char **trim_empty_lines(char **map)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = malloc(sizeof(char *) * count_lines(map));
	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][0])
		{
			new_map[j] = ft_strdup(map[i]);
			j ++;
		}
		i++;
	}
	new_map[j] = 0;
	free_tab(map);
	return (new_map);
}

int	check_code_color(char *code)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while(code[i])
	{
		if (!ft_isdigit(code[i]) && code[i] != ',')
			return (0);
		if (code[i] == ',')
		{
			count ++;
			if (code[i + 1] == ',' || code[i + 1] == 0 || i == 0)
			return (0);
		}
		i++;
	}
	if (count == 2)
		return (1);
	printf("color problem\n");
	return (0);
}

int get_color(t_color *color, char *code)
{
	char	**rgb;
	int		i;
	
	if (check_code_color(code) == 0)
	{
		printf("error code color\n");
		return (-1);
	}
	rgb = ft_split(code, ',');
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	if (color->r > 255 || color->g > 255 || color->b > 255)
		return (-1);
	free_tab(rgb);
	return (0);
}

int	norme(t_info *info, char **line)
{
	
	if (!ft_strncmp("F", line[0], 2147483647))
	{
		if (info->ground.r != -1 || !line[1])
			return (-1);
		if (get_color(&info->ground, line[1]) == -1)
			return (-1);
	}
	else if (!ft_strncmp("C", line[0], 2147483647))
	{
		if (info->sky.r != -1 || !line[1])
			return (-1);
		if (get_color(&info->sky, line[1]) == -1)
			return (-1);
	}
	else if (!ft_strncmp("WE", line[0], 21))
	{
		if (info->west_path || !line[1])
			return (-1);
		info->west_path = ft_strdup(line[1]);
	}
	else
		return (1);
	return (0);
}

int	get_info(t_info *info, char **line)
{
	if (!ft_strncmp("NO", line[0], 21))
	{
		if (info->north_path || !line[1])
			return (-1);
		info->north_path = ft_strdup(line[1]);
	}
	else if(!ft_strncmp("SO", line[0], 21))
	{
		if (info->south_path || !line[1])
			return (-1);
		info->south_path = ft_strdup(line[1]);
	}
	else if(!ft_strncmp("EA", line[0], 21))
	{
		if (info->east_path || !line[1])
			return (-1);
		info->east_path = ft_strdup(line[1]);
	}
	else
		return (norme(info, line));
	return (0);
}

int	lines_left(char **map, int i)
{
	int count;

	count = 0;
	while (map[i])
	{
		count ++;
		i++;
	}
	return (count + 1);
}

int	parse_first_elems(char **map, t_info *info)
{
	char	**line_split;
	int		i;
	int		j;
	int		map_start;

	map_start = 0;
	i = 0;
	while (map[i])
	{
		line_split = ft_split(map[i], ' ');
		map_start = get_info(info, line_split);
		if (map_start == 0 && line_split[1] && line_split[2])
		{
			printf("Error en el mapa expediente\n");
			map_start = -1;
		}
		free_tab(line_split);
		if (map_start != 0)
			break;
		i++;
	}
	if (map_start == -1)
		return (-1);
	info->pure_map = malloc(sizeof(char *) * lines_left(map, i));
	j = 0;
	while (map[i])
	{
		info->pure_map[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
	info->pure_map[j] = NULL;
	free_tab(map);
	return (0);
}