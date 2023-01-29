/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:50:57 by shiloub           #+#    #+#             */
/*   Updated: 2023/01/29 21:22:30 by shiloub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

typedef	struct s_color
{
	int	r;
	int g;
	int b;
}	t_color;
typedef struct s_info
{
	t_color sky;
	t_color ground;
	char *north_path;
	char *south_path;
	char *east_path;
	char *west_path;
	char **pure_map;
	
}	t_info;

int		check_error(int ac, char **av);
char	**parse_file(char *map_path);
void	free_tab(char **tab);
int		parse_first_elems(char **map, t_info *info);
char	*get_next_line(int fd);
int		ft_strfind(char *str, char c);
void    ft_putstr(char *str);
void	print_tab(char **tab);
char **trim_empty_lines(char **map);
void    set_spaces(char **map);
void    replace_spaces (char **map);
int	check_map(char **map);
void	free_infos(t_info *info);
int	check_empty_line_map(char **map);

#endif