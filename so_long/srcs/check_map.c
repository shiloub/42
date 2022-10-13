/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:36:16 by amontant          #+#    #+#             */
/*   Updated: 2022/03/10 17:00:18 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_map(char **map)
{
	if (check_walls(map) && check_player_exit(map) && check_rectangle(map))
		return (1);
	else
		return (0);
}
