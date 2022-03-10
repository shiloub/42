/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:36:16 by amontant          #+#    #+#             */
/*   Updated: 2022/03/10 13:32:26 by shiloub          ###   ########.fr       */
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

