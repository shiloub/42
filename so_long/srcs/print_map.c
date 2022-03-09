/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:17:47 by amontant          #+#    #+#             */
/*   Updated: 2022/03/09 19:00:10 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	*game->x = 0;
	*game->y = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			print_texture(game, game->map[i][j], *game->x, *game->y);
			*game->x = *game->x + 24;
			j++;
		}
		*game->y = *game->y + 24;
		*game->x = 0;
		i++;
	}
}

void	print_texture(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->ground, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->fruit, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->robot, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->door, x, y);
	else if (c == 'O')
		mlx_put_image_to_window(game->mlx, game->win, game->door_open, x, y);
}
