/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:00:32 by amontant          #+#    #+#             */
/*   Updated: 2022/03/09 14:44:15 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_cross(t_game *game)
{
	exit_game(game);
	return (0);
}

int	fonction(int key, t_game *game)
{
	if (key == 65307)
		exit_game(game);
	if (key == 65362 || key == 65364 || key == 65361 || key == 65363)
	{
		if (key == 65363)
			go_right(game->map);
		else if (key == 65361)
			go_left(game->map);
		else if (key == 65362)
			go_down(game->map);
		else if (key == 65364)
			go_up(game->map);
	}
	open_door_if_necessary(game->map);
	if (no_door(game->map))
		exit_game(game);
	print_map(game);
	printf("%d\n", key);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = set_game(av[1]);
	print_map(game);
	mlx_hook(game->win, 17, 1L << 17, quit_cross, game);
	mlx_key_hook(game->win, fonction, game);
	mlx_loop(game->mlx);
	return (0);
}
