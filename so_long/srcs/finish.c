/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:28:47 by amontant          #+#    #+#             */
/*   Updated: 2022/03/09 18:59:11 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->door);
	mlx_destroy_image(game->mlx, game->door_open);
	mlx_destroy_image(game->mlx, game->robot);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_image(game->mlx, game->fruit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	free_game(game);
	exit (0);
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

void	free_game(t_game *game)
{
	free(game->x);
	free(game->y);
	free(game->count);
	free(game);
}
