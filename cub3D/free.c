/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:35:52 by shiloub           #+#    #+#             */
/*   Updated: 2023/01/29 21:32:31 by shiloub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
	{
		free(tab);
		return ;
	}
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_infos(t_info *info)
{
	free(info->east_path);
	free(info->west_path);
	free(info->north_path);
	free(info->south_path);
	free_tab(info->pure_map);
	free(info);
}