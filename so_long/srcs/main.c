/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:00:32 by amontant          #+#    #+#             */
/*   Updated: 2022/03/09 18:59:53 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	quit_cross(t_game *game)
{
	exit_game(game);
	return (0);
}

int	fonction(int key, t_game *game)
{
	int	temp;

	temp = *game->count;
	if (key == 65307)
		exit_game(game);
	if (key == 65362 || key == 65364 || key == 65361 || key == 65363)
	{
		if (key == 65363)
			*game->count += go_right(game->map);
		else if (key == 65361)
			*game->count += go_left(game->map);
		else if (key == 65362)
			*game->count += go_down(game->map);
		else if (key == 65364)
			*game->count += go_up(game->map);
	}
	if (temp != *game->count)
		printf("->%d\n", *game->count);
	open_door_if_necessary(game->map);
	if (no_door(game->map))
		exit_game(game);
	print_map(game);
	return (0);
}

int	check_extention(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
		if (str[i] == '.')
		{
			if (str[i + 1] && str[i + 2] && str[i + 3] && !str[i + 4])
			{
				if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r')
					return (1);
			}
		}
	}
	return (0);
}

int	check_error(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (1);
	if (!check_extention(av[1]))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (check_error(ac, av))
	{
		printf("ERROR");
		return (0);
	}
	game = set_game(av[1]);
	print_map(game);
	mlx_hook(game->win, 17, 1L << 17, quit_cross, game);
	mlx_key_hook(game->win, fonction, game);
	mlx_loop(game->mlx);
	return (0);
}
