/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:04:46 by shiloub           #+#    #+#             */
/*   Updated: 2023/02/02 00:43:09 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_infos(t_info *infos)
{
	infos->pure_map = NULL;
	infos->east_path = NULL;
	infos->north_path = NULL;
	infos->south_path = NULL;
	infos->west_path = NULL;
	infos->ground.r = -1;
	infos->sky.r = -1;
}
int	check_all_elems(t_info *infos)
{
	if (!infos->east_path || !infos->west_path || !infos->north_path
		|| !infos->south_path || infos->ground.r == -1 || infos->sky.r == -1)
		return(0);
	return (1);
}
int main(int ac, char **av)
{
	t_info *infos;
	char	**map;

	if (check_error(ac, av))
	{
		printf("Error\nWrong argument\n");
		return (0);
	}
	map = parse_file(av[1]);
	if (!map)
	{
		printf("Error\n Cant read map file\n");
		return (0);
	}
	if (check_empty_line_map(map))
		return (0);
	map = trim_empty_lines(map);
	infos = malloc(sizeof(t_info));
	set_infos(infos);
	if (parse_first_elems(map, infos) == -1)
	{
		free_tab(map);
		free_infos(infos);
		return (0);
	}
	if (!check_all_elems(infos))
	{
		free_infos(infos);
		printf("textures or colors r missing\n");
		return (0);
	}
	
	
	printf("%s\n", infos->north_path);
	printf("%s\n", infos->south_path);
	printf("%s\n", infos->west_path);
	printf("%s\n", infos->east_path);
	printf("sky : %d,%d,%d\n", infos->sky.r, infos->sky.g, infos->sky.b);
	printf("ground : %d,%d,%d\n", infos->ground.r, infos->ground.g, infos->ground.b);
	printf("-------------------------------\n");

	
	replace_spaces(infos->pure_map);
	set_spaces(infos->pure_map);
	printf("-------------------------------\n");
	check_map(infos->pure_map);
	printf("-------------------------------\n");
	print_tab(infos->pure_map);
	free_infos(infos);
}
